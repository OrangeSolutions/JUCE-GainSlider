/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
GainTotalJuceAudioProcessorEditor::GainTotalJuceAudioProcessorEditor (GainTotalJuceAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    gainSlider.setSliderStyle (juce::Slider::SliderStyle::LinearVertical);
    gainSlider.setTextBoxStyle (juce::Slider::TextBoxBelow, false, 60, 25);
    gainSlider.setColour (juce::Slider::ColourIds::thumbColourId, juce::Colours::orange);
    gainSlider.setNumDecimalPlacesToDisplay (2);
    gainSlider.setTextValueSuffix (" dB");
    addAndMakeVisible (gainSlider);
    
    gainAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.mApvts, "GAIN", gainSlider);
    
    gainLabel.setFont (20.0f);
    gainLabel.setText ("Gain", juce::NotificationType::dontSendNotification);
    gainLabel.setJustificationType (juce::Justification::centredTop);
    gainLabel.attachToComponent (&gainSlider, false);
    
    setResizable (true, true);
    setSize (400, 300);
}

GainTotalJuceAudioProcessorEditor::~GainTotalJuceAudioProcessorEditor()
{
}

//==============================================================================
void GainTotalJuceAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::darkgrey);

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Gain Slider", 0, 0, getWidth(), 30, juce::Justification::centred, 1);
}

void GainTotalJuceAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    gainSlider.setBounds (20, 100, 100, ((getHeight() / 8) * 6)-100);
}
