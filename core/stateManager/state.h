#ifndef STATE_H
#define STATE_H

#include "stdafx.h"
#include "core/stateManager/statemanager.h"

class StateManager;

class State
{
public:
    State();
    virtual ~State();

    friend class StateManager;

protected:
    virtual void render () = 0; //Render object
    virtual void enter () = 0; //Enter a state;
    virtual void pause () = 0; //Pause a state;
    virtual void resume () = 0;
    virtual void exit () = 0;

    StateManager *stateMan;
    ProcessManager *processMan;
    InputManager *inputMan;
    controlMappingsManager *mappMan;

    GraphicManager *graphicMan;
    SpriteManager *spriteMan;

    AudioMixer *audioMix;
    AudioManager *audioMan;

    Camera *cameraMan;
};

#endif // STATE_H
