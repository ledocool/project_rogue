#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "stdafx.h"
#include "my_classes.h"

class MenuState : public State
{
public:
    MenuState ();
    ~MenuState();

protected:
    void render ();
    void processLogic(Uint32 ms);
    void enter ();
    void pause ();
    void resume ();
    void exit ();

private:
    std::vector <std::pair <int, std::string> > menuItems;
    int highlightedItem;
    bool keyUpPressed, keyDownPressed, keyLeftPressed, keyRightPressed, keyReturnPressed;
};

#endif // MENUSTATE_H
