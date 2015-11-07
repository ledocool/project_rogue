#ifndef STATE_H
#define STATE_H

#include "stdafx.h"

class state
{
public:
    virtual void render () = 0; //Render object

    virtual void enter () = 0; //Enter a state;
    virtual void pause () = 0; //Pause a state;
    virtual void resume () = 0;
    virtual void exit () = 0;

//    virtual void frameClicked () = 0;
//    virtual void keyIsDown () = 0;
//    virtual void keyIsUp () = 0;

    state();
    virtual ~state();
};

class gameState : public state
{
public:
    gameState ();
    ~gameState();

    void render ();
    void enter ();
    void pause ();
    void resume ();
    void exit ();

    gameState *getState () { return &_gState; }

private:
    static gameState _gState;
};

class menuState;

class menuState : public state
{
public:
    menuState ();
    ~menuState();

    void render ();
    void enter ();
    void pause ();
    void resume ();
    void exit ();

    menuState *getState () { return &_mState; }

private:
    static menuState _mState;

};

#endif // STATE_H
