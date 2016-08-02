#ifndef KEYCOMBINATION_H
#define KEYCOMBINATION_H
#include "input/keystroke.h"

using namespace keys;

class keyCombination
{
public:
    keyCombination(playerAction a, keystroke k);
    playerAction getAction();
    keystroke getStroke();

private:
    keystroke _key;
    playerAction _action;
};

#endif // KEYCOMBINATION_H
