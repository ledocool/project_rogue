#include "keycombination.h"

keyCombination::keyCombination(playerAction a, keystroke k)
{
    _action = a;
    _key = k;
}

playerAction keyCombination::getAction()
{
    return _action;
}

keystroke keyCombination::getStroke()
{
    return _key;
}

