/*
  ==============================================================================

    WallComponent.cpp
    Created: 6 Oct 2023 12:40:27am
    Author:  Antony Tsakiris

  ==============================================================================
*/

#include <JuceHeader.h>
#include "WallComponent.h"
using namespace juce;

//==============================================================================
WallComponent::WallComponent()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

WallComponent::~WallComponent()
{
}

void WallComponent::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */
    //drowing a rectangle
    Rectangle <float> wall(200, 200, 200, 120);
    g.fillCheckerBoard(wall, 20, 10, Colours::sandybrown, Colours::saddlebrown);
    g.drawRect(wall);
    
}

void WallComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
