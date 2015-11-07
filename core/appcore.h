#ifndef APPCORE_H
#define APPCORE_H

#include "stdafx.h"

class appCore
{
public:
    void init();   //Asks all subsystems to init themselves
    void start();  //Starts the game and sets it for running
    void finish(); //Stops program from running

    appCore();

private:
//    createProcess();

    stateManager *stateMan;
    processManager *processMan;
    inputManager *inputMan;

    graphicManager *graphicMan;
    spriteManager *spriteMan;

    audioMixer *audioMix;
    audioManager *audioMan;

    camera *cameraMan;

};

#endif // APPCORE_H
