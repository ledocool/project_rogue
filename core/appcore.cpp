#include "appcore.h"

void AppCore::init()
{
    createControllerObjects();

    int w, h, px, py;
    config_t *cfg;
    config_init(cfg);
    int cfg_read = config_read_file(cfg, "config.ini");

    if(!cfg_read)
    {
        throw BasicException("Unable to read config file", errorCodes::graphicInitError);
    }

    if( !config_lookup_int(cfg, "window_propreties.width", &w) )
    {
        throw BasicException("Unable to read config file", errorCodes::graphicInitError);
    }

    if( !config_lookup_int(cfg, "window_propreties.height", &h) )
    {
        throw BasicException("Unable to read config file", errorCodes::graphicInitError);
    }

    if( !config_lookup_int(cfg, "window_propreties.window_x", &px) )
    {
        throw BasicException("Unable to read config file", errorCodes::graphicInitError);
    }

    if( !config_lookup_int(cfg, "window_propreties.window_y", &py) )
    {
        throw BasicException("Unable to read config file", errorCodes::graphicInitError);
    }

    config_destroy(cfg);

    if(px < 0 || py < 0)
    {
        px = SDL_WINDOWPOS_UNDEFINED;
        py = SDL_WINDOWPOS_UNDEFINED;
    }

    graphicMan->init("Game engine", px, py, h, w);
    audioMix->init();

    cameraMan->set(w/2., h/2.);
}

void AppCore::createControllerObjects()
{
    stateMan = Singleton <StateManager> ::get();
    inputMan = Singleton <InputManager> ::get();
    graphicMan = Singleton <GraphicManager> ::get();
    spriteMan = Singleton <SpriteManager> ::get();
    cameraMan = Singleton <Camera> ::get();
    audioMix = Singleton <AudioMixer> ::get();
    audioMan = Singleton <AudioManager> ::get();
    mappMan = Singleton <ControlMappingsManager> ::get();
}

void AppCore::initSDL()
{
    if (SDL_Init(0) != 0)
    {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        throw BasicException( SDL_GetError(), errorCodes::graphicInitError );
    }
}

void AppCore::loadConfig(int &w, int &h, int &px, int &py)
{
    config_t *cfg;
    config_init(cfg);
    int cfg_read = config_read_file(cfg, "config.ini");

    if(!cfg_read)
    {
        throw BasicException("Unable to read config file", errorCodes::graphicInitError);
    }

    if( !config_lookup_int(cfg, "window_propreties.width", &w) )
    {
        throw BasicException("Unable to read config file", errorCodes::graphicInitError);
    }

    if( !config_lookup_int(cfg, "window_propreties.height", &h) )
    {
        throw BasicException("Unable to read config file", errorCodes::graphicInitError);
    }

    if( !config_lookup_int(cfg, "window_propreties.window_x", &px) )
    {
        throw BasicException("Unable to read config file", errorCodes::graphicInitError);
    }

    if( !config_lookup_int(cfg, "window_propreties.window_y", &py) )
    {
        throw BasicException("Unable to read config file", errorCodes::graphicInitError);
    }

    config_destroy(cfg);
}

void AppCore::start()
{
    stateMan->pushState(new MenuState());
    loop();
}

void AppCore::finish()
{
    graphicMan->freeAll();
    SDL_Quit();
}

AppCore::AppCore()
{
    this->init();
}

AppCore::~AppCore()
{
    this->finish();
}

int AppCore::loop()
{    
    Uint32 dt = 16;
    Uint32 frameTime, lastUpdateTime, currentUpdateTime = SDL_GetTicks(), lastFpsTime, lastProcessingTime, processingElapsed;
    //Uint32 fps = 0;
    bool quit = false;

    lastProcessingTime = lastFpsTime = lastUpdateTime = currentUpdateTime;
    inputMan->updateState();

    while(!quit)
    {
        currentUpdateTime = SDL_GetTicks();
        frameTime = currentUpdateTime - lastUpdateTime;
        lastUpdateTime = currentUpdateTime;

        int timeleft = dt - frameTime;
        uint iters = 0;
        do
        {
            currentUpdateTime = SDL_GetTicks();
            processingElapsed = currentUpdateTime - lastProcessingTime;
            lastProcessingTime = currentUpdateTime;
            //Update inputs;
            if( inputMan->updateState() || !stateMan->process(processingElapsed) )
            {
                quit = true;
                break;
            }
            iters += 1;
        }
        while(currentUpdateTime < lastUpdateTime + timeleft);

//        fps += 1;
//        if(currentUpdateTime - lastFpsTime >= 1000)
//        {
//            lastFpsTime = currentUpdateTime;
//            std::cout << "Fps: " << fps << std::endl;
//            fps = 0;
//        }

        if(!stateMan->render())
        {
            quit = true;
        }
    }
    return 0;
}
