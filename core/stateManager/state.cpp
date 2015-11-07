#include "state.h"

state::state()
{

}

state::~state()
{

}

gameState::gameState()
{

}

gameState::~gameState()
{

}

void gameState::render()
{
    printf ("Imma rendering gamestate\n");
}

void gameState::enter()
{
    printf ("Imma entering gamestate\n");
}

void gameState::pause()
{
    printf ("Imma pausing gamestate\n");
}

void gameState::resume()
{
    printf ("Imma resuming gamestate\n");
}

void gameState::exit()
{
    printf ("Imma exiting gamestate\n");
}

menuState::menuState()
{

}

menuState::~menuState()
{

}

void menuState::render()
{
    printf ("Imma rendering memu\n");
}

void menuState::enter()
{
    printf ("Imma entering memu\n");
}

void menuState::pause()
{
    printf ("Imma pausing memu\n");
}

void menuState::resume()
{
    printf ("Imma resuming memu\n");
}

void menuState::exit()
{
    printf ("Imma exiting memu\n");
}
