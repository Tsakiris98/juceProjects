/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
//#include <juce_audio_formats/format/juce_AudioFormatWriter.h>
using namespace juce;

//==============================================================================
/**
*/
class Plugin1AudioProcessor  : public juce::AudioProcessor
                            #if JucePlugin_Enable_ARA
                             , public juce::AudioProcessorARAExtension
                            #endif
{
public:
    //==============================================================================
    Plugin1AudioProcessor();
    ~Plugin1AudioProcessor() override;
    
    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    
#ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
#endif
    
    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;
    
    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;
    
    //==============================================================================
    const juce::String getName() const override;
    
    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;
    
    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;
    
    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    void getFromDlyBuffer(juce::AudioBuffer<float>& buffer, int channel,const int bufferLength, const int DlyBufferLength, const float* BufferReadPointer, const float* DlyReadPointer);
    
private:
    
    AudioBuffer<float> gDlyBuffer;
    int gWritePoiter {0}; //initialization
    int gSampleRate {44100};//Creating a gl;obal variable of the sample rate
    
    void FillDelayBuffer(int channel,const int bufferLength, const int DlyBufferLength, const float* BufferReadPointer, const float* DlyReadPointer);
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Plugin1AudioProcessor)
    
};
