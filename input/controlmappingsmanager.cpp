#include "controlmappingsmanager.h"

ControlMappingsManager::ControlMappingsManager()
{
    using namespace keys;
    config_t *cfg;
    config_init(cfg);
    if( CONFIG_FALSE == config_read_file(cfg, "config.ini" ))
      throw BasicException("Error reading control config", errorCodes::noError);
    int c, e;

      /*config_lookup_int(cfg, "basic_controls.GO_UP.code", &c);
      config_lookup_int(cfg, "basic_controls.GO_UP.event", &e);
      this->addCombination(KeyCombination(GO_UP, (keystroke)c), e);

      config_lookup_int(cfg, "basic_controls.GO_DOWN.code", &c);
      config_lookup_int(cfg, "basic_controls.GO_DOWN.event", &e);
      this->addCombination(KeyCombination(GO_DOWN, (keystroke)c), e);

      config_lookup_int(cfg, "basic_controls.GO_LEFT.code", &c);
      config_lookup_int(cfg, "basic_controls.GO_LEFT.event", &e);
      this->addCombination(KeyCombination(GO_LEFT, (keystroke)c), e);

      config_lookup_int(cfg, "basic_controls.GO_RIGHT.code", &c);
      config_lookup_int(cfg, "basic_controls.GO_RIGHT.event", &e);
      this->addCombination(KeyCombination(GO_RIGHT, (keystroke)c), e);

      config_lookup_int(cfg, "basic_controls.MENU_DOWN.code", &c);
      config_lookup_int(cfg, "basic_controls.MENU_DOWN.event", &e);
      this->addCombination(KeyCombination(MENU_DOWN, (keystroke)c), e);

      config_lookup_int(cfg, "basic_controls.MENU_UP.code", &c);
      config_lookup_int(cfg, "basic_controls.MENU_UP.event", &e);
      this->addCombination(KeyCombination(MENU_UP, (keystroke)c), e);

      config_lookup_int(cfg, "basic_controls.MENU_LEFT.code", &c);
      config_lookup_int(cfg, "basic_controls.MENU_LEFT.event", &e);
      this->addCombination(KeyCombination(MENU_LEFT, (keystroke)c), e);

      config_lookup_int(cfg, "basic_controls.MENU_RIGHT.code", &c);
      config_lookup_int(cfg, "basic_controls.MENU_RIGHT.event", &e);
      this->addCombination(KeyCombination(MENU_RIGHT, (keystroke)c), e);

      config_lookup_int(cfg, "basic_controls.MENU_UP.code", &c);
      config_lookup_int(cfg, "basic_controls.MENU_UP.event", &e);
      this->addCombination(KeyCombination(MENU_UP, (keystroke)c), e);

      config_lookup_int(cfg, "basic_controls.MENU_SELECT.code", &c);
      config_lookup_int(cfg, "basic_controls.MENU_SELECT.event", &e);
      this->addCombination(KeyCombination(MENU_SELECT, (keystroke)c), e);

      config_lookup_int(cfg, "basic_controls.ZOOM_IN.code", &c);
      config_lookup_int(cfg, "basic_controls.ZOOM_IN.event", &e);
      this->addCombination(KeyCombination(ZOOM_IN, (keystroke)c), e);

      config_lookup_int(cfg, "basic_controls.ZOOM_OUT.code", &c);
      config_lookup_int(cfg, "basic_controls.ZOOM_OUT.event", &e);
      this->addCombination(KeyCombination(ZOOM_OUT, (keystroke)c), e);*/

    config_lookup_int(cfg, "basic_controls.GO_UP.code", &c);
    config_lookup_int(cfg, "basic_controls.GO_UP.event", &e);
    _keys[GO_UP] = (keystroke)c;

    config_lookup_int(cfg, "basic_controls.GO_DOWN.code", &c);
    config_lookup_int(cfg, "basic_controls.GO_DOWN.event", &e);
    _keys[GO_DOWN] = (keystroke)c;

    config_lookup_int(cfg, "basic_controls.GO_LEFT.code", &c);
    config_lookup_int(cfg, "basic_controls.GO_LEFT.event", &e);
    _keys[GO_LEFT] = (keystroke)c;

    config_lookup_int(cfg, "basic_controls.GO_RIGHT.code", &c);
    config_lookup_int(cfg, "basic_controls.GO_RIGHT.event", &e);
    _keys[GO_RIGHT] = (keystroke)c;

    config_lookup_int(cfg, "basic_controls.MENU_SELECT.code", &c);
    config_lookup_int(cfg, "basic_controls.MENU_SELECT.event", &e);
    _keys[MENU_SELECT] = (keystroke)c;

    config_lookup_int(cfg, "basic_controls.ZOOM_IN.code", &c);
    config_lookup_int(cfg, "basic_controls.ZOOM_IN.event", &e);
    _keys[ZOOM_IN] = (keystroke)c;

    config_lookup_int(cfg, "basic_controls.ZOOM_OUT.code", &c);
    config_lookup_int(cfg, "basic_controls.ZOOM_OUT.event", &e);
    _keys[ZOOM_OUT] = (keystroke)c;

    config_destroy(cfg);
}

keystroke ControlMappingsManager::getKey(playerAction a)
{
    return _keys[a];
}

/*std::vector<playerAction> ControlMappingsManager::getActions(InputManager *inputMan)
{
    std::vector <playerAction> acts;
    uint    szHeld = _keyHeldCombinations.size(),
            szDown = _keyPressedCombinations.size();
    acts.reserve(szHeld + szDown);

    for(uint i=0; i < szHeld; i++)
    {
        if(inputMan->keyIsHeld(_keyHeldCombinations[i].getStroke()))
        {
            acts.push_back(_keyHeldCombinations[i].getAction());
        }
    }

    return acts;
}*/

/*void ControlMappingsManager::addCombination(KeyCombination kk, uint type)
{
    switch(type)
    {
        case 0:
            _keyPressedCombinations.push_back(kk);
            break;
        case 1:
            _keyHeldCombinations.push_back(kk);
            break;
    }
}*/

