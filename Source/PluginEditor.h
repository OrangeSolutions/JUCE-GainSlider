/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class GainTotalJuceAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    GainTotalJuceAudioProcessorEditor (GainTotalJuceAudioProcessor&);
    ~GainTotalJuceAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::Slider gainSlider;
    juce::Label gainLabel;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> gainAttachment;
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    GainTotalJuceAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GainTotalJuceAudioProcessorEditor)
};
