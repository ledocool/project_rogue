#include "gamestate.h"


GameState::GameState()
{
}

GameState::~GameState()
{

}

void GameState::render()
{
    graphicMan->resetMatrix(); //draw in screens coordinates;

    graphicMan->scaleViewport(  1., 1. );
    graphicMan->moveTo( 0., 0. );
    graphicMan->clear();

    graphicMan->swapBuffers();
}

void GameState::enter()
{
    printf ("Imma entering gamestate\n");
}

void GameState::pause()
{
    printf ("Imma pausing gamestate\n");
}

void GameState::resume()
{
    printf ("Imma resuming gamestate\n");
}

void GameState::exit()
{
    printf ("Imma exiting gamestate\n");
}
