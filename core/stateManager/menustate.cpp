#include "menustate.h"
#include "gamestate.h"

MenuState::MenuState()
{
    menuItems.resize(2);
    //gman = Singleton<GraphicManager>::get();
    //inputMan = Singleton<InputManager>::get();
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

    graphicMan->drawText(0, 0, 0, 0, "Helloworld");

    graphicMan->swapBuffers();
}

void MenuState::enter()
{
    menuItems[0] = std::pair<int, std::string> (0, "Start");
    menuItems[1] = std::pair<int, std::string> (0, "Exit");
}

void MenuState::pause()
{
    //throw Exception("Unable to pause state", errorCodes::stateError);
}

void MenuState::resume()
{
    //throw Exception("Unable to resume state", errorCodes::stateError);
}

void MenuState::exit()
{
    printf ("Imma exiting memu\n");
}

void MenuState::loop()
{

}
