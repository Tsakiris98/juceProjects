/*
  ==============================================================================

    SunComponent.cpp
    Created: 7 Oct 2023 12:41:06am
    Author:  Antony Tsakiris

  ==============================================================================
*/

#include <JuceHeader.h>
#include "SunComponent.h"
using namespace juce;
//==============================================================================
SunComponent::SunComponent()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

SunComponent::~SunComponent()
{
}

void SunComponent::paint (juce::Graphics& g)
{
    g.setColour(Colours::yellow);
    g.drawEllipse(400, 50, 50, 50, 10.0f);
   
   
}

void SunComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
