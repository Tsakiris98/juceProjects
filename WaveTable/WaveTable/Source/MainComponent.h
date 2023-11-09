#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::AudioAppComponent,
                       public Slider::Listener
{
public:
    void  sliderValueChanged(Slider *slider) override
    {
       if (slider == &F_slider)
           frequency = F_slider.getValue();
           
    }
    
    void updateFrequency()
    {
        inclrementPoint = waveTableSize * frequency/currentSampleRate;
        phase = fmod(phase + inclrementPoint, waveTableSize); 
    }
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    //==============================================================================
    void paint (juce::Graphics& g) override;
    void resized() override;

private:
    //==============================================================================
    // Your private member variables go here...
    Array<float> waveTable;
    double waveTableSize;
    double frequency;
    double phase;
    double inclrementPoint;
    float*  output;
    float amplitude;
    double currentSampleRate;
    
    Slider F_slider ,A_slider;
    
    
    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
