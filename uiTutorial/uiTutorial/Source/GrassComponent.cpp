/*
  ==============================================================================

    GrassComponent.cpp
    Created: 7 Oct 2023 12:05:20am
    Author:  Antony Tsakiris

  ==============================================================================
*/

#include <JuceHeader.h>
#include "GrassComponent.h"
using namespace juce;

//==============================================================================
GrassComponent::GrassComponent()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

GrassComponent::~GrassComponent()
{
}

void GrassComponent::paint (juce::Graphics& g)
{
    g.setColour(Colours::green);
    g.drawLine(10, 325, getWidth()-10, 325, 10);

}

void GrassComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
