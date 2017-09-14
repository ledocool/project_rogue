#ifndef CONTROLMAPPINGSMANAGER_H
#define CONTROLMAPPINGSMANAGER_H

#include "stdafx.h"
#include "input/inputmanager.h"
#include "input/keystroke.h"
#include "input/keycombination.h"

class InputManager;

class ControlMappingsManager
{
public:
    ControlMappingsManager();
    /*std::vector <playerAction> getActions(InputManager *inputMan);*/
    keystroke getKey(playerAction a);

private:
    /*void addCombination(KeyCombination kk, uint type);*/
    /*std::vector<KeyCombination> _keyHeldCombinations, _keyPressedCombinations;*/
    std::map<keys::playerAction, keys::keystroke> _keys;
};

#endif // CONTROLMAPPINGSMANAGER_H
