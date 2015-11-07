#include "appcore.h"

void appCore::init()
{
    stateMan = singleton <stateManager> ::get();
    processMan = singleton <processManager> ::get();
    inputMan = singleton <inputManager> ::get();
    graphicMan = singleton <graphicManager> ::get();
    spriteMan = singleton <spriteManager> ::get();
    cameraMan = singleton <camera> ::get();
    audioMix = singleton <audioMixer> ::get();
    audioMan = singleton <audioManager> ::get();

    // TODO: set sdl init to a different function
    if (SDL_Init(0) != 0)
    {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
    }

    //Inits video subsystem, which inits window
    graphicMan->init("Imma window", 30, 30, 480, 640); //init grafonium subsystem
    audioMix->init(); //init sound subsystem
}

void appCore::start()
{
    sprite *spt;
    spt = new sprite("./tex.png");
    singleton <spriteManager> ::get()->regSprite(spt);

    sound *snd;
    music *mus;
    //mus = new music("./What does the fox say.mp3");
    snd = new sound("./alarm.wav");
    snd->setVolume(100);

    bool stillGoing = true;

    while(stillGoing)
    {
        float addX=0, addY=0;
        if(inputMan->updateState() == true)
            stillGoing = false;

        if(inputMan->keyIsDown(KEY_z))
            audioMix->playSound(snd);

        //if(inputMan->keyIsDown(KEY_m))
        //    audioMix->playMusic(mus);

        if(inputMan->keyIsHeld(KEY_UP))
            addY = +0.5;
        if(inputMan->keyIsHeld(KEY_DOWN))
            addY = -0.5;
        if(inputMan->keyIsHeld(KEY_LEFT))
            addX = +0.5;
        if(inputMan->keyIsHeld(KEY_RIGHT))
            addX = -0.5;
        if(inputMan->keyIsHeld(KEY_EQUALS))
            cameraMan->setZoom(cameraMan->getZoom() + 0.0001);
        if(inputMan->keyIsHeld(KEY_MINUS))
            cameraMan->setZoom(cameraMan->getZoom() - 0.0001);

        if(inputMan->keyIsDown(KEY_r))
        {
            cameraMan->set(640/2, 480/2);
            cameraMan->setZoom(0);
        }

        cameraMan->move(addX, addY);
        graphicMan->render();
    }
}

void appCore::finish()
{
    graphicMan->freeAll();
    SDL_Quit();
}

appCore::appCore()
{
}
