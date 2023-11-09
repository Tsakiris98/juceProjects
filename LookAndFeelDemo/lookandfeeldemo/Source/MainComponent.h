#pragma once

#include <JuceHeader.h>
using namespace juce;
//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class OtherLookAndFeel : public LookAndFeel_V4
{
public:
    OtherLookAndFeel()
    {
    setColour(Slider::rotarySliderOutlineColourId, Colours::chocolate);
    setColour(Slider::rotarySliderFillColourId, Colours::blanchedalmond);
    setColour(Slider::thumbColourId, Colours::black);
    }

};

class MainComponent  : public juce::Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
    Slider dial1;
    Slider dial2;
    
    LookAndFeel_V4 otherLookAndFeel;
    OtherLookAndFeel otherlookandfeel;
};
