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
    std::vector <playerAction> getActions(InputManager *inputMan);

private:
    std::vector<KeyCombination> _keyCombinations;
};

#endif // CONTROLMAPPINGSMANAGER_H
