#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "stdafx.h"

class MenuState : public State
{
public:
    MenuState ();
    ~MenuState();

    void render ();
    void enter ();
    void pause ();
    void resume ();
    void exit ();

    MenuState *getState () { return &_mState; }

private:
    void loop();

    static MenuState _mState;
    std::vector <std::pair <int, std::string> > menuItems;
};


#endif // MENUSTATE_H
