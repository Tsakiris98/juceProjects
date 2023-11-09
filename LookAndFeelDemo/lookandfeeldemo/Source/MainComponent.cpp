#include "MainComponent.h"
using namespace juce;
//==============================================================================
MainComponent::MainComponent()
{
    setSize (600, 400);
    addAndMakeVisible(dial1);
    addAndMakeVisible(dial2);
    
    dial1.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    dial2.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    
    dial1.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 25);
    dial2.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 25);
        getLookAndFeel().setColour(Slider::thumbColourId, Colours::purple);
    
    //dial1.setColour(Slider::thumbColourId, Colours::purple);
    //dial2.setColour(Slider::thumbColourId, Colours::green);
    
//    dial1.setColour(Slider::rotarySliderOutlineColourId, Colours::white);
//    dial2.setColour(Slider::rotarySliderOutlineColourId, Colours::white);
//    
//    dial1.setColour(Slider::rotarySliderFillColourId, Colours::purple);
//    dial2.setColour(Slider::rotarySliderFillColourId, Colours::green);
//    
    
    dial1.setLookAndFeel(&otherlookandfeel);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
  

}

void MainComponent::resized()
{
    const int border = 20;
    const int dialWidth = getWidth() / 2 - border;
    const int dialHeight = getHeight() / 2 - border;
    
    dial1.setBounds(border, border, dialWidth, dialHeight);
    dial2.setBounds(getWidth()/2, border, dialWidth, dialHeight);
}
