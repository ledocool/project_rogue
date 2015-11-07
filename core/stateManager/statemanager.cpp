#include "statemanager.h"

stateManager::stateManager()
{
}

void stateManager::render()
{
    stateStack.top()->render();
}

void stateManager::changeState(state *st)
{
    class state *delState;
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

void stateManager::pushState(state *st)
{
    if( !stateStack.empty() )
        stateStack.top()->pause(); //pause current runlevel

    //add another
    stateStack.push(st);
    stateStack.top()->enter();
}

void stateManager::popState()
{
    state *st;
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
