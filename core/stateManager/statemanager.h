#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include "stdafx.h"
#include "core/stateManager/state.h"
#include "state.h"

class StateManager
{
public:
    bool render();
    void changeState( State *st );
    void pushState( State* st );
    void popState();
    StateManager();

private:
    std::stack <State *> stateStack; //currentState;


};

#endif // STATEMANAGER_H
