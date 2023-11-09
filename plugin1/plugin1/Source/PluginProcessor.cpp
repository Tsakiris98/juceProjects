/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Plugin1AudioProcessor::Plugin1AudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
}

Plugin1AudioProcessor::~Plugin1AudioProcessor()
{
}

//==============================================================================
const juce::String Plugin1AudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool Plugin1AudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool Plugin1AudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool Plugin1AudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double Plugin1AudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int Plugin1AudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int Plugin1AudioProcessor::getCurrentProgram()
{
    return 0;
}

void Plugin1AudioProcessor::setCurrentProgram (int index)
{
}

const juce::String Plugin1AudioProcessor::getProgramName (int index)
{
    return {};
}

void Plugin1AudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void Plugin1AudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    const int NumInChannels = getTotalNumInputChannels();
    const int DlyBufferSize = sampleRate * 2 ;
    gDlyBuffer.setSize(NumInChannels, DlyBufferSize);
    gSampleRate = sampleRate;
}

void Plugin1AudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool Plugin1AudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void Plugin1AudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
    
//        for(int n=0; n < buffer.getNumSamples(); n++)
//        {}
        const int bufferLength = buffer.getNumSamples();
        const int DlyBufferLength = gDlyBuffer.getNumSamples();
            
            for (int channel = 0; channel < totalNumInputChannels; ++channel)
            {
                const float* BufferReadPointer = buffer.getReadPointer(channel);
                const float* DlyReadPointer = gDlyBuffer.getReadPointer(channel);
                
                FillDelayBuffer(channel, bufferLength, DlyBufferLength, BufferReadPointer, DlyReadPointer);
                getFromDlyBuffer(buffer, channel, bufferLength, DlyBufferLength, BufferReadPointer, DlyReadPointer);
            }
            
            gWritePoiter += bufferLength;
            gWritePoiter %= DlyBufferLength;
        
}

void Plugin1AudioProcessor::FillDelayBuffer(int channel,const int bufferLength, const int DlyBufferLength, const float* BufferReadPointer, const float* DlyReadPointer)
{
    //---copy data drom buffer to delay buffer----//
    if (DlyBufferLength > bufferLength + gWritePoiter)
    {
        gDlyBuffer.copyFromWithRamp(channel, gWritePoiter, BufferReadPointer, bufferLength, 0.8, 0.8);
    }
    else
    {
        const int bufferRemaining = DlyBufferLength - gWritePoiter;
        gDlyBuffer.copyFromWithRamp(channel, gWritePoiter, BufferReadPointer, bufferRemaining, 0.8, 0.8);
        gDlyBuffer.copyFromWithRamp(channel, 0, BufferReadPointer, bufferLength - bufferRemaining, 0.8, 0.8);
    }
}


void Plugin1AudioProcessor::getFromDlyBuffer(juce::AudioBuffer<float>& buffer, int channel,const int bufferLength, const int DlyBufferLength, const float* BufferReadPointer, const float* DlyReadPointer)
{
    int DelayTime = 500;//ms
    const int readPosition = static_cast<int> (DlyBufferLength + gWritePoiter - (DelayTime / 1000 * gSampleRate) % DlyBufferLength);
    if (DlyBufferLength > bufferLength + readPosition)
    {
        buffer.addFrom(channel, 0, DlyReadPointer + readPosition, bufferLength);
    }
    else
    {
        const int bufferRemaining = DlyBufferLength - readPosition;
        buffer.addFrom(channel, 0, DlyReadPointer + readPosition, bufferRemaining);
        buffer.addFrom(channel, bufferRemaining, DlyReadPointer, bufferLength - bufferRemaining);
    }
}

//==============================================================================
bool Plugin1AudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* Plugin1AudioProcessor::createEditor()
{
    return new Plugin1AudioProcessorEditor (*this);
    
}

//==============================================================================
void Plugin1AudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void Plugin1AudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new Plugin1AudioProcessor();
}
