#include "controlmappingsmanager.h"

controlMappingsManager::controlMappingsManager()
{
    using namespace keys;
    _inputfile = "config.ini";

    config_t *cfg;

    config_init(cfg);
    int cfg_read = config_read_file(cfg, _inputfile.c_str());
    int a;
    config_lookup_int(cfg, "basic_controls.GO_UP", &a);
    _keyCombinations.push_back( keyCombination(GO_UP, (keystroke)a) );
    config_lookup_int(cfg, "basic_controls.GO_DOWN", &a);
    _keyCombinations.push_back( keyCombination(GO_DOWN, (keystroke)a) );
    config_lookup_int(cfg, "basic_controls.GO_LEFT", &a);
    _keyCombinations.push_back( keyCombination(GO_LEFT, (keystroke)a) );
    config_lookup_int(cfg, "basic_controls.GO_RIGHT", &a);
    _keyCombinations.push_back( keyCombination(GO_RIGHT, (keystroke)a) );
    config_lookup_int(cfg, "basic_controls.ZOOM_IN", &a);
    _keyCombinations.push_back( keyCombination(ZOOM_IN, (keystroke)a) );
    config_lookup_int(cfg, "basic_controls.ZOOM_OUT", &a);
    _keyCombinations.push_back( keyCombination(ZOOM_OUT, (keystroke)a) );


    config_destroy(cfg);
}

std::vector<playerAction> controlMappingsManager::getActions(inputManager *inputMan)
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

