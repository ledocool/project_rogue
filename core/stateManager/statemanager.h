#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include "stdafx.h"
#include "my_classes.h"
#include "state.h"

class State;

class StateManager
{
public:
    bool render();
    bool process(std::vector<keys::playerAction> actions);
    void changeState( State *st );
    void pushState( State* st );
    void popState();
    StateManager();

private:
    std::stack <State *> stateStack; //currentState;


};

#endif // STATEMANAGER_H
