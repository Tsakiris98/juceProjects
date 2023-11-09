#include "MainComponent.h"
//#include <juce_core/maths/juce_MathsFunctions.h>
#include "../JuceLibraryCode/JuceHeader.h"
    

//==============================================================================
MainComponent::MainComponent()
{
    // Make sure you set the size of the component after
    // you add any child components.
    setSize (800, 600);
    addAndMakeVisible(F_slider);
    F_slider.setName("Frequency");
    F_slider.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
    F_slider.addListener(this);
    F_slider.setRange(50, 1000);
    
    
    
    
    addAndMakeVisible(A_slider);

    // Some platforms require permissions to open input channels so request that here
    if (juce::RuntimePermissions::isRequired (juce::RuntimePermissions::recordAudio)
        && ! juce::RuntimePermissions::isGranted (juce::RuntimePermissions::recordAudio))
    {
        juce::RuntimePermissions::request (juce::RuntimePermissions::recordAudio,
                                           [&] (bool granted) { setAudioChannels (granted ? 2 : 0, 2); });
    }
    else
    {
        // Specify the number of input and output channels that we want to open
        setAudioChannels (2, 2);
    }
}

MainComponent::~MainComponent()
{
    // This shuts down the audio device and clears the audio source.
    shutdownAudio();
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    frequency = 50;
    phase = 0;
    waveTableSize = 1024;
    
    output = 0;
    amplitude = 0.2f;
    currentSampleRate = deviceManager.getCurrentAudioDevice()->getCurrentSampleRate();
 
    //----------bulding the wavetable----------//
    for(int i = 0; i < waveTableSize; i++)
    {
        waveTable.insert(i, sin(2.0f * MathConstants<double>::pi * i/waveTableSize));
    }
    
}

void MainComponent::getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill)
{
    
    for (int n = 0; n < bufferToFill.buffer->getNumSamples(); n++)
     {
      
         for (int ch = 0; ch < bufferToFill.buffer->getNumChannels(); ch++)
         {
             
          float* const currentChannel = bufferToFill.buffer->getWritePointer(ch, bufferToFill.startSample);
          currentChannel[n] = amplitude * waveTable[(int)phase];
         }

         updateFrequency();
     }
    
}

void MainComponent::releaseResources()
{
    // This will be called when the audio device stops, or when it is being
    // restarted due to a setting change.

    // For more details, see the help for AudioProcessor::releaseResources()
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    // You can add your drawing code here!
}

void MainComponent::resized()
{
    const int labelspace = 100;
    
    F_slider.setBounds(labelspace, 20, getWidth()-labelspace, 20);
}
