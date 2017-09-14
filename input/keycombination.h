#ifndef KEYCOMBINATION_H
#define KEYCOMBINATION_H
#include "input/keystroke.h"

using namespace keys;

//Deprecated. Do not use until usage proves to be nesessary;

class KeyCombination
{
public:
    KeyCombination(playerAction a, keystroke k);
    playerAction getAction();
    keystroke getStroke();

private:
    keystroke _key;
    playerAction _action;
};

#endif // KEYCOMBINATION_H
