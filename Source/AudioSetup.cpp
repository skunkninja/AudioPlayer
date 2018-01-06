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
//[/Headers]

#include "AudioSetup.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
CAudioSetup::CAudioSetup (AudioDeviceManager& deviceManager_)
    : deviceManager(deviceManager_)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (groupComponent = new GroupComponent ("new group",
                                                            TRANS("Audio device setup")));

    addAndMakeVisible (component = new AudioDeviceSelectorComponent (deviceManager, 0, 0, 0, 2, false, false, true, false));
    component->setName ("new component");


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 300);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

CAudioSetup::~CAudioSetup()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    groupComponent = nullptr;
    component = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void CAudioSetup::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff001836));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void CAudioSetup::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    groupComponent->setBounds (8, 0, getWidth() - 16, getHeight() - 4);
    component->setBounds (16, 16, getWidth() - 32, getHeight() - 28);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="CAudioSetup" componentName=""
                 parentClasses="public Component" constructorParams="AudioDeviceManager&amp; deviceManager_"
                 variableInitialisers="deviceManager(deviceManager_)" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="1"
                 initialWidth="600" initialHeight="300">
  <BACKGROUND backgroundColour="ff001836"/>
  <GROUPCOMPONENT name="new group" id="1222bd71541cf06c" memberName="groupComponent"
                  virtualName="" explicitFocusOrder="0" pos="8 0 16M 4M" title="Audio device setup"/>
  <GENERICCOMPONENT name="new component" id="29e3f1f9451b331e" memberName="component"
                    virtualName="AudioDeviceSelectorComponent" explicitFocusOrder="0"
                    pos="16 16 32M 28M" class="Component" params="deviceManager, 0, 0, 0, 2, false, false, true, false"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
