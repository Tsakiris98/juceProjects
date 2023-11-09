/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class SimpleGainAudioProcessorEditor  : public juce::AudioProcessorEditor,
public juce::Slider::Listener
{
public:
    SimpleGainAudioProcessorEditor (SimpleGainAudioProcessor&);
    ~SimpleGainAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void sliderVlueChanged(juce::Slider* slider); //protoryping/declair the function that converts slider valuses to db
private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Slider gainSlider;
    
    SimpleGainAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SimpleGainAudioProcessorEditor)
};


