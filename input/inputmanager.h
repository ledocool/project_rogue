#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "stdafx.h"
#include "input/keystroke.h"

//KeyStates
#define KEY_IS_UP      0
#define KEY_IS_DOWN    1
#define KEY_IS_HELD    2
#define KEY_IS_TOGGLED 3
#define KEY_IS_NOTFOUND -1

//! Note: more states can be added

class InputManager
{
public:
    InputManager ();

    bool keyIsUp (keys::keystroke keyNum);
    bool keyIsDown (keys::keystroke keyNum);
    bool keyIsHeld (keys::keystroke keyNum);
    bool keyIsToggled (keys::keystroke keyNum);

    bool mouseDown (keys::mouseClick mouseKeyNum);

    bool updateState();

private:
    std::map < int, short > keyStates;
    int m_MouseX, m_MouseY;
    std::vector < short > mouseStates;
    std::map < int, short > videoStates;

};

#endif // INPUTMANAGER_H
