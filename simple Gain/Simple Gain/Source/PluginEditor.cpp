/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SimpleGainAudioProcessorEditor::SimpleGainAudioProcessorEditor (SimpleGainAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (200, 400);
    
    addAndMakeVisible(gainSlider);
    gainSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    gainSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 25);
    gainSlider.setRange(-48, 0);
    gainSlider.setValue(-1.0);
    gainSlider.addListener(this);
    
}

SimpleGainAudioProcessorEditor::~SimpleGainAudioProcessorEditor()
{
}

//==============================================================================
void SimpleGainAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    
   
    
}
void SimpleGainAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    gainSlider.setBounds(getLocalBounds());
}

void SimpleGainAudioProcessorEditor::sliderVlueChanged(juce::Slider *slider)
{
    if (slider == &gainSlider)
    {
        audioProcessor.rawVolume = pow(10, gainSlider.getValue() / 20);
    }
}
