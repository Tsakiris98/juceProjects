#pragma once

#include <JuceHeader.h>
#include "WallComponent.h"
#include "GrassComponent.h"
#include "RoofComponent.h"
#include "SunComponent.h"
#include "TextComponent.h"
//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;// override is a keyword that ensures that you know that each component(buttons sliders...) it is going to have it's own paint and resized function that only controls that component.Overrides the fanctionality of overide and paint. Paint function hat to do anythis that comes with graphics text knobs etc.
    void resized() override;// resized is what happens if your window is resized (getting your component smaller bigger depenting on the resized action of the window)

private:
    //==============================================================================
    // Your private member variables go here...


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
    
    WallComponent wall;//creating a wallcomponent object
    GrassComponent grass;
    RoofComponent roof;
    SunComponent sun;
    TextComponent text;
};
