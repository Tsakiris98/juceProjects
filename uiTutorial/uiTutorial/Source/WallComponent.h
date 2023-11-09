/*
  ==============================================================================

    WallComponent.h
    Created: 6 Oct 2023 12:40:27am
    Author:  Antony Tsakiris

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>


//==============================================================================
/*
*/
class WallComponent  : public juce::Component
{
public:
    WallComponent();
    ~WallComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WallComponent)
    
};
