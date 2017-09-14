#ifndef APPCORE_H
#define APPCORE_H

#include "stdafx.h"
#include "stateManager/menustate.h"
#include "stateManager/gamestate.h"

class AppCore
{
public:
    void start(); //Starts the game and sets it for running
    AppCore();
    ~AppCore();

private:
    int loop();
    void init();   //Asks all subsystems to init themselves
    void createControllerObjects();
    void initSDL();
    void loadConfig(int &w, int &h, int &px, int &py);

    void finish(); //Stops program from running

    StateManager *stateMan;
    InputManager *inputMan;
    ControlMappingsManager *mappMan;

    GraphicManager *graphicMan;
    SpriteManager *spriteMan;

    AudioMixer *audioMix;
    AudioManager *audioMan;

    Camera *cameraMan;

};

#endif // APPCORE_H
