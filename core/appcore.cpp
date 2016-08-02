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
    mappMan = singleton <controlMappingsManager> ::get();

    // TODO: set sdl init to a different function
    if (SDL_Init(0) != 0)
    {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        throw SDL_GetError();
    }

    //Inits video subsystem, which inits window
    graphicMan->init("Imma window", 30, 30, 480, 640); //init grafonium subsystem
    audioMix->init(); //init sound subsystem
}

void appCore::start()
{
    loop();
}

int appCore::registerSprite(const char *spritePath)
{
    sprite *spt;
    spt = new sprite(spritePath);
    spriteMan->regSprite(spt);
    return 0;
}

int appCore::registerSound(const char *soundPath)
{
    sound *snd;
    snd = new sound(soundPath);
    audioMan->regSound(snd);
    return 0;
}

void appCore::finish()
{
    graphicMan->freeAll();
    SDL_Quit();
}

appCore::appCore()
{
    this->init();
}

appCore::~appCore()
{
    this->finish();
}

int appCore::loop()
{
    Uint32 t = 0, dt = 17;
    Uint32 frameTime, lastUpdateTime, currentUpdateTime = SDL_GetTicks();
    bool quit = false;

    lastUpdateTime = currentUpdateTime;

    while(!quit)
    {
        currentUpdateTime = SDL_GetTicks();
        frameTime = currentUpdateTime - lastUpdateTime;
        lastUpdateTime = currentUpdateTime;

        float addX = 0.0f,
              addY = 0.0f;

        while(frameTime > 0)
        {
            Uint32 cStep = frameTime > dt ? dt : frameTime;

            //Update inputs;
            quit = inputMan->updateState();
            std::vector<playerAction> actions = mappMan->getActions(inputMan);

            for(int i=0; i<actions.size(); i++)
            {
                if(actions[i] == keys::GO_UP)
                    addY = +0.5;
                if(actions[i] == keys::GO_DOWN)
                    addY = -0.5;
                if(actions[i] == keys::GO_LEFT)
                    addX = +0.5;
                if(actions[i] == keys::GO_RIGHT)
                    addX = -0.5;
                if(actions[i] == keys::ZOOM_IN)
                    cameraMan->setZoom(cameraMan->getZoom() + 0.0001);
                if(actions[i] == keys::ZOOM_OUT)
                    cameraMan->setZoom(cameraMan->getZoom() - 0.0001);
            }
            cameraMan->move(addX, addY);

            frameTime -= cStep;
            t += cStep; //Current time period;
        }

        graphicMan->render();
    }

    return 0;
}
