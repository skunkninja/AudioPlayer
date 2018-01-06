/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.2.0

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
#include "AudioSetup.h"
//[/Headers]

#include "MainComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MainContentComponent::MainContentComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..
#if JUCE_WINDOWS
    getLookAndFeel().setDefaultSansSerifTypefaceName(L"Microsoft YaHei");
#endif
#if JUCE_MAC
    getLookAndFeel().setDefaultSansSerifTypefaceName(L"Arial Unicode MS");
#endif
    //[/Constructor_pre]

    addAndMakeVisible (setupButton = new TextButton ("new button"));
    setupButton->setButtonText (TRANS("Setup..."));
    setupButton->addListener (this);


    //[UserPreSize]
    AudioDeviceManager::AudioDeviceSetup currentSetup;

//    RuntimePermissions::request(RuntimePermissions::recordAudio,
//        [this](bool wasGranted)
//    {
//        if (!wasGranted)
        {
            // e.g. display an error or initialise with 0 input channels
            audioDeviceManager.initialise(0, 2, nullptr, true, String(), nullptr);
        }
//        else
//        {
//            audioDeviceManager.initialise(2, 2, nullptr, true, String(), nullptr);
//        }
//    }
//    );
    audioDeviceManager.getAudioDeviceSetup(currentSetup);

    //Set current buffer size to 128, and current sample rate to 48k.
    //currentSetup.bufferSize = 512;
    //currentSetup.sampleRate = 48000.0;
    //audioDeviceManager.setAudioDeviceSetup(currentSetup, true);

    audioDeviceManager.addAudioCallback(&juceAudioCallBack);

    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

MainContentComponent::~MainContentComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    audioDeviceManager.removeAudioCallback(&juceAudioCallBack);
    //[/Destructor_pre]

    setupButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MainContentComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MainContentComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    setupButton->setBounds (272, 8, 71, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MainContentComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == setupButton)
    {
        //[UserButtonCode_setupButton] -- add your button handler code here..
        CAudioSetup dlg(audioDeviceManager);
        DialogWindow::showModalDialog(L"Midi input device selection",
            &dlg,
            this,
            Colours::azure, true, true);
        
        //sample rate may be changed here.

        //[/UserButtonCode_setupButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MainContentComponent" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <TEXTBUTTON name="new button" id="12a6e66179bb5222" memberName="setupButton"
              virtualName="" explicitFocusOrder="0" pos="272 8 71 24" buttonText="Setup..."
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
