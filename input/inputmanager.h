#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "stdafx.h"
#include "input/keystroke.h"
#include "my_classes.h"
#include "controlmappingsmanager.h"

//KeyStates
#define KEY_IS_UP      (0)
#define KEY_IS_DOWN    (1)
#define KEY_IS_HELD    (2)
#define KEY_IS_TOGGLED (3)
#define KEY_IS_NOTFOUND (-1)

//! Note: more states can be added

class InputManager
{
public:
    InputManager ();

    bool keyIsUp (keys::keystroke keyNum);
    bool keyIsUp (keys::playerAction action);
    bool keyIsDown (keys::keystroke keyNum);
    bool keyIsDown (keys::playerAction action);
    bool keyIsHeld (keys::keystroke keyNum);
    bool keyIsHeld (keys::playerAction action);
    bool keyIsToggled (keys::keystroke keyNum);
    uint keyState(keys::keystroke keyNum);

    bool mouseDown (keys::mouseClick mouseKeyNum);

    bool updateState();

private:
    std::map < int, short > _keyStates;
    int _m_MouseX, _m_MouseY;
    std::vector < short > _mouseStates;
    std::map < int, short > _videoStates;

    ControlMappingsManager *mappMan;
};

#endif // INPUTMANAGER_H
