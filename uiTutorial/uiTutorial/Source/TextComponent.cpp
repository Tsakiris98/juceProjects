/*
  ==============================================================================

    TextComponent.cpp
    Created: 7 Oct 2023 1:37:33am
    Author:  Antony Tsakiris

  ==============================================================================
*/

#include <JuceHeader.h>
#include "TextComponent.h"
using namespace juce;
//==============================================================================
TextComponent::TextComponent()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

TextComponent::~TextComponent()
{
}

void TextComponent::paint (juce::Graphics& g)
{
    Font theFont("Brush Script MT","Italic" ,50.0f);
    g.setFont(theFont);
    g.drawText("Antonis Plugin", 10, 10, 400, 60, Justification::topLeft);
}

void TextComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
