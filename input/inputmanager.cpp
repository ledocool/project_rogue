#include "inputmanager.h"

inputManager::inputManager()
{
    //maxKeys = 255; //No, srsly, can't be more;
    //keyStates.resize(256);
    mouseStates.resize(5);
}

bool inputManager::keyIsUp(keystroke keyNum)
{
    if (keyStates[keyNum] == KEY_IS_UP)
        return true;
    else
        return false;
}

bool inputManager::keyIsDown(keystroke keyNum)
{
    if (keyStates[keyNum] == KEY_IS_DOWN)
        return true;
    else
        return false;
}

bool inputManager::keyIsHeld(keystroke keyNum)
{
    if (keyStates[keyNum] == KEY_IS_HELD)
        return true;
    else
        return false;
}

bool inputManager::keyIsToggled(keystroke keyNum)
{
    if (keyStates[keyNum] == KEY_IS_TOGGLED)
        return true;
    else
        return false;
}

bool inputManager::mouseDown(mouseClick mouseKeyNum)
{
    if(mouseStates[mouseKeyNum] == KEY_IS_DOWN)
        return true;
    else
        return false;
}

bool inputManager::updateState()
{
    graphicManager *graphic = singleton <graphicManager> ::get();

    SDL_Event event;
    std::vector < keystroke > keys;
    std::vector < mouseClick > clicks;
    //std::vector <  >

    while ( SDL_PollEvent( &event ) )
    {
        switch( event.type )
        {
            case SDL_QUIT:
                return true;
                break;
            case SDL_KEYDOWN:
                keyStates[event.key.keysym.sym] = KEY_IS_DOWN;
                keys.push_back((keystroke)event.key.keysym.sym);
                break;
            case SDL_KEYUP:
                keyStates[event.key.keysym.sym] = KEY_IS_UP;
                keys.push_back((keystroke)event.key.keysym.sym);
                break;
            case SDL_MOUSEMOTION:
                m_MouseX = event.motion.x;
                m_MouseY = event.motion.y; //Temp. Then we will check window coords
                break;
            case SDL_MOUSEBUTTONUP:
                mouseStates[event.button.button] = KEY_IS_UP;
                clicks.push_back((mouseClick)event.button.which);
                break;
            case SDL_MOUSEBUTTONDOWN:
                mouseStates[event.button.button] = KEY_IS_DOWN;
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

    for( std::map<int, short>::iterator itr = keyStates.begin(); itr != keyStates.end(); itr++ )
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



