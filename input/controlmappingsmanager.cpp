#include "controlmappingsmanager.h"

ControlMappingsManager::ControlMappingsManager()
{
    using namespace keys;    
    config_t *cfg;
    config_init(cfg);
    config_read_file(cfg, "config.ini");
    int a;

    config_lookup_int(cfg, "basic_controls.GO_UP", &a);
    _keyCombinations.push_back( KeyCombination(GO_UP, (keystroke)a) );
    config_lookup_int(cfg, "basic_controls.GO_DOWN", &a);
    _keyCombinations.push_back( KeyCombination(GO_DOWN, (keystroke)a) );
    config_lookup_int(cfg, "basic_controls.GO_LEFT", &a);
    _keyCombinations.push_back( KeyCombination(GO_LEFT, (keystroke)a) );
    config_lookup_int(cfg, "basic_controls.GO_RIGHT", &a);
    _keyCombinations.push_back( KeyCombination(GO_RIGHT, (keystroke)a) );
    config_lookup_int(cfg, "basic_controls.ZOOM_IN", &a);
    _keyCombinations.push_back( KeyCombination(ZOOM_IN, (keystroke)a) );
    config_lookup_int(cfg, "basic_controls.ZOOM_OUT", &a);
    _keyCombinations.push_back( KeyCombination(ZOOM_OUT, (keystroke)a) );
    config_lookup_int(cfg, "basic_controls.CHANGE_STATE", &a);
    _keyCombinations.push_back( KeyCombination(CHANGE_STATE, (keystroke)a) );

    config_destroy(cfg);
}

std::vector<playerAction> ControlMappingsManager::getActions(InputManager *inputMan)
{
    std::vector <playerAction> acts;
    uint sz = _keyCombinations.size();
    acts.reserve(sz);

    for(uint i=0; i < sz; i++)
    {
        if(inputMan->keyIsHeld(_keyCombinations[i].getStroke()))
        {
            acts.push_back(_keyCombinations[i].getAction());
        }
    }

    return acts;
}

