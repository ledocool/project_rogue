#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "stdafx.h"
#include "my_classes.h"

class GameState : public State
{
public:
    GameState ();
    ~GameState();

protected:
    void render ();
    void enter ();
    void processLogic(std::vector<keys::playerAction> actions);
    void pause ();
    void resume ();
    void exit ();

private:
    Map _map;

    double mapX, mapY; //coordinates of map's top left corner on the scene;
    uint mapW, mapH;
};
#endif // GAMESTATE_H
