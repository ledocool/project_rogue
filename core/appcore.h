#ifndef APPCORE_H
#define APPCORE_H

#include "stdafx.h"

class appCore
{
public:
    void start();  //Starts the game and sets it for running
    int registerSprite(const char *spritePath);
    int registerSound(const char *soundPath);
    appCore();
    ~appCore();

private:
    int loop();
    void init();   //Asks all subsystems to init themselves
    void finish(); //Stops program from running

    stateManager *stateMan;
    processManager *processMan;
    inputManager *inputMan;
    controlMappingsManager *mappMan;

    graphicManager *graphicMan;
    spriteManager *spriteMan;

    audioMixer *audioMix;
    audioManager *audioMan;

    camera *cameraMan;

};

#endif // APPCORE_H
