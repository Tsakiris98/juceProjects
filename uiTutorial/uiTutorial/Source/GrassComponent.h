/*
  ==============================================================================

    GrassComponent.h
    Created: 7 Oct 2023 12:05:20am
    Author:  Antony Tsakiris

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class GrassComponent  : public juce::Component
{
public:
    GrassComponent();
    ~GrassComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GrassComponent)
};
