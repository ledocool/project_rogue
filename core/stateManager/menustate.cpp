#include "menustate.h"
#include "gamestate.h"

MenuState::MenuState()
{
    menuItems.resize(2);
}

MenuState::~MenuState()
{

}

void MenuState::render()
{
    graphicMan->resetMatrix(); //draw in screens coordinates;
    graphicMan->scaleViewport(  1., 1. );
    graphicMan->moveTo( 0., 0. );
    graphicMan->clear();

    graphicMan->drawRect(2, 2, 5, 5, 0, 0, 0, 1);
    graphicMan->drawRect(10, 10, 5, 5, 0, 0, 0, 1);

    graphicMan->drawText(40, 50, "Start (q)");
    graphicMan->drawText(40, 100, "Exit");


    graphicMan->swapBuffers();
}

void MenuState::processLogic(std::vector<playerAction> actions)
{
    for(uint i=0; i<actions.size(); i++)
    {
        if(actions[i] == keys::CHANGE_STATE)
        {
            stateMan->pushState(new GameState());
        }
    }
}

void MenuState::enter()
{
}

void MenuState::pause()
{
    //throw BasicException("Unable to resume state", errorCodes::stateError);//Exception("Unable to pause state", errorCodes::stateError);
}

void MenuState::resume()
{
    //throw BasicException("Unable to resume state", errorCodes::stateError);
}

void MenuState::exit()
{
    printf ("Imma exiting memu\n");
}

