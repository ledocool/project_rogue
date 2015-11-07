#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include "stdafx.h"
#include "core/stateManager/state.h"

class stateManager// : public singleton <stateManager>
{
public:
    void render();
    void changeState( state *st );
    void pushState( state* st );
    void popState();

    stateManager();

private:
    std::stack <state *> stateStack; //currentState;

};

#endif // STATEMANAGER_H
