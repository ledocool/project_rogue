#include "keycombination.h"

KeyCombination::KeyCombination(playerAction a, keystroke k)
{
    _action = a;
    _key = k;
}

playerAction KeyCombination::getAction()
{
    return _action;
}

keystroke KeyCombination::getStroke()
{
    return _key;
}

