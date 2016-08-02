#ifndef CONTROLMAPPINGSMANAGER_H
#define CONTROLMAPPINGSMANAGER_H

#include "stdafx.h"
#include "input/keystroke.h"
#include "input/keycombination.h"

class controlMappingsManager
{
public:
    controlMappingsManager();
    std::vector <playerAction> getActions(inputManager *inputMan);

private:
    std::vector<keyCombination> _keyCombinations;
    //std::string _inputfile;
};

#endif // CONTROLMAPPINGSMANAGER_H
