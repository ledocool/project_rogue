#include "inputmanager.h"

InputManager::InputManager()
{
    //maxKeys = 255; //No, srsly, can't be more;
    //keyStates.resize(256);
    _mouseStates.resize(5);
    mappMan = Singleton<ControlMappingsManager>::get();
}

bool InputManager::keyIsUp(keystroke keyNum)
{
    if (_keyStates[keyNum] == KEY_IS_UP)
        return true;
    else
        return false;
}

bool InputManager::keyIsUp(playerAction action)
{
    return keyIsUp(mappMan->getKey(action));
}

bool InputManager::keyIsDown(keystroke keyNum)
{
    if (_keyStates[keyNum] == KEY_IS_DOWN)
        return true;
    else
        return false;
}

bool InputManager::keyIsDown(playerAction action)
{
    return keyIsDown(mappMan->getKey(action));
}

bool InputManager::keyIsHeld(keystroke keyNum)
{
    if (_keyStates[keyNum] == KEY_IS_HELD)
        return true;
    else
        return false;
}

bool InputManager::keyIsHeld(playerAction action)
{
    return keyIsHeld(mappMan->getKey(action));
}

bool InputManager::keyIsToggled(keystroke keyNum)
{
    if (_keyStates[keyNum] == KEY_IS_TOGGLED)
        return true;
    else
        return false;
}

uint InputManager::keyState(keystroke keyNum)
{
    return _keyStates[keyNum];
}

bool InputManager::mouseDown(mouseClick mouseKeyNum)
{
    if(_mouseStates[mouseKeyNum] == KEY_IS_DOWN)
        return true;
    else
        return false;
}

bool InputManager::updateState()
{
    GraphicManager *graphic = Singleton <GraphicManager> ::get();

    SDL_Event event;
    std::vector < keystroke > keys;
    std::vector < mouseClick > clicks;

    while ( SDL_PollEvent( &event ) )
    {
        switch( event.type )
        {
            case SDL_QUIT:
                return true;
                break;
            case SDL_KEYDOWN:
                _keyStates[event.key.keysym.sym] = KEY_IS_DOWN;
                keys.push_back((keystroke)event.key.keysym.sym);
                break;
            case SDL_KEYUP:

                _keyStates[event.key.keysym.sym] = KEY_IS_UP;
                keys.push_back((keystroke)event.key.keysym.sym);
                break;
            case SDL_MOUSEMOTION:
                _m_MouseX = event.motion.x;
                _m_MouseY = event.motion.y; //Temp. Then we will check window coords
                break;
            case SDL_MOUSEBUTTONUP:
                _mouseStates[event.button.button] = KEY_IS_UP;
                clicks.push_back((mouseClick)event.button.which);
                break;
            case SDL_MOUSEBUTTONDOWN:
                _mouseStates[event.button.button] = KEY_IS_DOWN;
                clicks.push_back((mouseClick)event.button.which);
                break;

            case SDL_WINDOWEVENT:
                if(event.window.event == SDL_WINDOWEVENT_RESIZED)
                    graphic->resizeViewport();
                break;

            default:
                break;
        }
    }

    //check to see if any keys haven't been released but were press
    //ie being held

    for( std::map<int, short>::iterator itr = _keyStates.begin(); itr != _keyStates.end(); itr++ )
    {
        //put no status flag
        if(itr->second == KEY_IS_UP)
        {
            bool keyFound = false;
            for(unsigned int i=0; i < keys.size(); i++)
            {
                if(keys[i] == itr->first)
                {
                    keyFound = true;
                    break;
                }
            }

            if( !keyFound )
            {
                itr->second = KEY_IS_NOTFOUND;
            }
        }
        else if( itr->second == KEY_IS_DOWN)
        {
            bool keyFound = false;
            for(unsigned int i = 0; i < keys.size(); i++)
            {
                if(keys[i] == itr->first)
                {
                    keyFound = true;
                    break;
                }
            }

            if( !keyFound )
            {
                itr->second = KEY_IS_HELD;
            }
        }
    }

    return false;
}



