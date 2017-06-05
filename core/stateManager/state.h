#ifndef STATE_H
#define STATE_H

#include "stdafx.h"
#include "my_classes.h"
#include "core/stateManager/statemanager.h"
#include "input/controlmappingsmanager.h"

class InputManager;
class StateManager;
class ControlMappingsManager;

class State
{
public:
    State();
    virtual ~State();

    friend class StateManager;

protected:
    virtual void render () = 0; //Render object
    virtual void processLogic (std::vector<keys::playerAction> actions) = 0;
    virtual void enter () = 0; //Enter a state;
    virtual void pause () = 0; //Pause a state;
    virtual void resume () = 0;
    virtual void exit () = 0;

    State *getState () { return this; }

    StateManager *stateMan;
    InputManager *inputMan;
    ControlMappingsManager *mappMan;

    GraphicManager *graphicMan;
    SpriteManager *spriteMan;

    AudioMixer *audioMix;
    AudioManager *audioMan;

    Camera *cameraMan;
};

#endif // STATE_H
