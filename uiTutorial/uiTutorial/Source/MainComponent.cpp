#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (600, 400);//initial window size
    
    
    addAndMakeVisible(wall);//make the component visible to the parent component.
    addAndMakeVisible(grass);
    addAndMakeVisible(roof);
    addAndMakeVisible(sun);
    addAndMakeVisible(text);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
    
    wall.setBounds(getLocalBounds());
    grass.setBounds(getLocalBounds());
    roof.setBounds(getLocalBounds());
    sun.setBounds(getLocalBounds());
    text.setBounds(getLocalBounds());
}
