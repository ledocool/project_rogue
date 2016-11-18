#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "stdafx.h"

class GameState : public State
{
public:
    GameState ();
    ~GameState();

    void render ();

protected:
    void enter ();
    void pause ();
    void resume ();
    void exit ();

    GameState *getState () { return &_gState; }

private:
    static GameState _gState;
    //GraphicManager *gman;
    //Camera *cameraMan;

    bool quit;
};
#endif // GAMESTATE_H
