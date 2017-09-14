#include "menustate.h"
#include "gamestate.h"

MenuState::MenuState()
{
    using namespace std;
    menuItems.push_back(pair<int, string>(0, "Start"));
    menuItems.push_back(pair<int, string>(0, "Options"));
    menuItems.push_back(pair<int, string>(0, "Credits"));
    menuItems.push_back(pair<int, string>(0, "Quit"));
    highlightedItem = -1;
    //keyPressed =
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

    GLdouble height = 40.;

    for(int i=0; i<menuItems.size(); i++)
    {
        if(i == highlightedItem)
        {
            graphicMan->drawText(40., height, menuItems[i].second, 0.6, 0.6, 0.6, 1.);
        }else{
            graphicMan->drawText(40., height, menuItems[i].second, 0., 0., 0., 1.);
        }
        height += 50;
    }

    graphicMan->swapBuffers();
}

void MenuState::processLogic(Uint32 ms)
{
    if(inputMan->keyIsDown(keys::GO_UP))
    {
        if(highlightedItem > 0) highlightedItem -= 1;
        keyUpPressed = true;
    }
    if(inputMan->keyIsDown(keys::GO_DOWN))
    {
        if(highlightedItem < menuItems.size() - 1) highlightedItem += 1;
        keyDownPressed = true;
    }
    if(inputMan->keyIsDown(keys::MENU_SELECT))
    {
        if(highlightedItem == 0)
        {
            stateMan->changeState(new GameState());
        }
        keyReturnPressed = true;
    }
}

void MenuState::enter()
{
    highlightedItem = 0;
}

void MenuState::pause()
{
}

void MenuState::resume()
{
}

void MenuState::exit()
{
}

