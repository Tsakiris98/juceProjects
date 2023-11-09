#include "MainComponent.h"
using namespace juce;
//==============================================================================
MainComponent::MainComponent()
{
    dial1.setSliderStyle(Slider::SliderStyle::Rotary);
    dial1.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
    addAndMakeVisible(dial1);
    
    dial2.setSliderStyle(Slider::SliderStyle::Rotary);
    dial2.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
    addAndMakeVisible(dial2);
    
    slider1.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
    slider1.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
    addAndMakeVisible(slider1);
    
    setSize (600, 400);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    g.fillAll(Colours::aquamarine);

    
    
//        //creating a rectangle that will be our section area
//    Rectangle<int> totalArea = getLocalBounds();// starts with the whole window area
//    Rectangle<int> sectionArea = totalArea.removeFromTop(totalArea.getHeight()/2);// removes the top of the rectangle by half of the whole window heigh.
//    Rectangle<int> sectionArea2 = sectionArea.removeFromRight(sectionArea.getWidth()/2);//then removes from the half of the right side of the rectangle.
//    
//    g.setColour(Colours::red);
//    g.drawRect(sectionArea);
//    
    
    
    
}

void MainComponent::resized()
{
    const int border = 10;
    
    Rectangle <int> area = getLocalBounds();
    
    Rectangle<int>dialArea = area.removeFromTop(area.getHeight()/2);
    dial1.setBounds(dialArea.removeFromLeft(area.getWidth()/2).reduced(border));
    dial2.setBounds(dialArea.removeFromRight(area.getWidth()/2).reduced(border));
    
    Rectangle<int> sliderArea = area.removeFromBottom(area.getBottom()/2);
    slider1.setBounds(sliderArea.removeFromLeft(area.getWidth()/2).reduced(border));
}
