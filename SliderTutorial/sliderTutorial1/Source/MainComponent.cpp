#include "MainComponent.h"
using namespace juce;
//==============================================================================
MainComponent::MainComponent()
{
    setSize (600, 400);
    
    addAndMakeVisible(frecuenceSlider);//make the slider visible
    frecuenceSlider.setRange(50, 5000);//set min and max value to the slider
    frecuenceSlider.setTextValueSuffix("Hz"); //set name to the values.
    frecuenceSlider.addListener(this);
    frecuenceSlider.setValue(500);//initial value
    frecuenceSlider.setSkewFactorFromMidPoint(500.0);
    frecuenceSlider.setTextBoxStyle(Slider::TextBoxLeft, false, 120, frecuenceSlider.getTextBoxHeight());
        addAndMakeVisible(frequencyLabel);
        frequencyLabel.setText("Frequency", dontSendNotification);
        frequencyLabel.attachToComponent(&frecuenceSlider, true);
    
    addAndMakeVisible(durationSlider);
    durationSlider.setRange(1.0/ frecuenceSlider.getMaximum(), 1.0 /frecuenceSlider.getMinimum());
    durationSlider.setTextValueSuffix("s");
    durationSlider.addListener(this);
    durationSlider.setSkewFactorFromMidPoint(0.002);
    durationSlider.setTextBoxStyle(Slider::TextBoxLeft, false, 120, frecuenceSlider.getTextBoxHeight());
        addAndMakeVisible(durationLabel);
        durationLabel.setText("Duration", dontSendNotification);
        durationLabel.attachToComponent(&durationSlider, true);
    
    
    
    
    
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
    const int border = 120;//pixels
    frecuenceSlider.setBounds(border, 20, getWidth()-border, 20);
    
    durationSlider.setBounds(border, 50, getWidth()-border, 50);

    
}
