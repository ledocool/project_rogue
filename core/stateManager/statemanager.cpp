#include "statemanager.h"

StateManager::StateManager()
{
}

bool StateManager::render()
{
    if(stateStack.empty())
    {
        return false;
    }
    stateStack.top()->render();
    return true;
}

void StateManager::changeState(State *st)
{
    class State *delState;
    if( !stateStack.empty() )
    {
        stateStack.top()->exit(); //pause current runlevel
        delState = stateStack.top();
        stateStack.pop();
        delete delState;
    }

    stateStack.push(st);
    stateStack.top()->enter();
}

void StateManager::pushState(State *st)
{
    if( !stateStack.empty() )
        stateStack.top()->pause(); //pause current runlevel

    //add another
    stateStack.push(st);
    stateStack.top()->enter();
}

void StateManager::popState()
{
    State *st;
    if( !stateStack.empty() )
    {
        stateStack.top()->exit(); //pause current runlevel
        st = stateStack.top();
        stateStack.pop();
        delete st;
    }

    if( !stateStack.empty() )
        stateStack.top()->resume();
}
