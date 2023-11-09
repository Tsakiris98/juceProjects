#pragma once

#include <JuceHeader.h>
using namespace juce;
//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::Component, 
                       public Slider::Listener
{
                        
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
   
    void sliderValueChanged (Slider* slider) override
    {
     if (slider == &frecuenceSlider)
         durationSlider.setValue(1.0 / frecuenceSlider.getValue());
        else if (slider == &durationSlider)
            frecuenceSlider.setValue(1.0 / durationSlider.getValue());
    }

private:
    //==============================================================================
    // Your private member variables go here...
    
    Slider frecuenceSlider;
    Label frequencyLabel;
    
    Slider durationSlider;
    Label durationLabel;
    


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
