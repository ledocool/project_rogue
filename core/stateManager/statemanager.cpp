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

bool StateManager::process(std::vector<playerAction> actions)
{
    if(stateStack.empty())
    {
        return false;
    }
    stateStack.top()->processLogic(actions);
    return true;
}

void StateManager::changeState(State *st)
{
    class State *delState;
    if( !stateStack.empty() )
    {
        stateStack.top()->exit();
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
        stateStack.top()->pause();

    stateStack.push(st);
    stateStack.top()->enter();
}

void StateManager::popState()
{
    State *st;
    if( !stateStack.empty() )
    {
        stateStack.top()->exit();
        st = stateStack.top();
        stateStack.pop();
        delete st;
    }

    if( !stateStack.empty() )
        stateStack.top()->resume();
}
