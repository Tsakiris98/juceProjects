/*
  ==============================================================================

    RoofComponent.cpp
    Created: 7 Oct 2023 12:15:43am
    Author:  Antony Tsakiris

  ==============================================================================
*/

#include <JuceHeader.h>
#include "RoofComponent.h"
using namespace juce;
//==============================================================================
RoofComponent::RoofComponent()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

RoofComponent::~RoofComponent()
{
}

void RoofComponent::paint (juce::Graphics& g)
{
    g.setColour(Colours::brown);
    Path p;
        p.startNewSubPath(200, 190);
        p.lineTo(400, 190);
        p.lineTo(300, 140);
        p.closeSubPath();
    g.fillPath(p);
    g.strokePath(p, PathStrokeType(2.0f));
}

void RoofComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
