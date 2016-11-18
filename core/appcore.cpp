#include "appcore.h"

void AppCore::init()
{
    stateMan = Singleton <StateManager> ::get();
    processMan = Singleton <ProcessManager> ::get();
    inputMan = Singleton <InputManager> ::get();
    graphicMan = Singleton <GraphicManager> ::get();
    spriteMan = Singleton <SpriteManager> ::get();
    cameraMan = Singleton <Camera> ::get();
    audioMix = Singleton <AudioMixer> ::get();
    audioMan = Singleton <AudioManager> ::get();
    mappMan = Singleton <controlMappingsManager> ::get();

    // TODO: set sdl init to a different function
    if (SDL_Init(0) != 0)
    {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        throw SDL_GetError();
    }

    //Inits video subsystem, which inits window

    int w, h, px, py;

    config_t *cfg;
    config_init(cfg);
    int cfg_read = config_read_file(cfg, "config.ini");

    if(!cfg_read)
    {
        throw Exception("Unable to read config file", errorCodes::graphicInitError);
    }

    if( !config_lookup_int(cfg, "window_propreties.width", &w) )
    {
        throw Exception("Unable to read config file", errorCodes::graphicInitError);
    }

    if( !config_lookup_int(cfg, "window_propreties.height", &h) )
    {
        throw Exception("Unable to read config file", errorCodes::graphicInitError);
    }

    if( !config_lookup_int(cfg, "window_propreties.window_x", &px) )
    {
        throw Exception("Unable to read config file", errorCodes::graphicInitError);
    }

    if( !config_lookup_int(cfg, "window_propreties.window_y", &py) )
    {
        throw Exception("Unable to read config file", errorCodes::graphicInitError);
    }

    config_destroy(cfg);

    if(px < 0 || py < 0)
    {
        px = SDL_WINDOWPOS_UNDEFINED;
        py = SDL_WINDOWPOS_UNDEFINED;
    }

    graphicMan->init("Game engine", px, py, h, w); //init grafonium subsystem
    audioMix->init(); //init sound subsystem

    cameraMan->set(w/2., h/2.);
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
    Uint32 t = 0, dt = 17;
    Uint32 frameTime, lastUpdateTime, currentUpdateTime = SDL_GetTicks();
    bool quit = false;
    bool switchedState = false;

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

            for(uint i=0; i<actions.size(); i++)
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
                    cameraMan->setZoom(cameraMan->getZoom() + 0.001);
                if(actions[i] == keys::ZOOM_OUT)
                    cameraMan->setZoom(cameraMan->getZoom() - 0.001);

                if(actions[i] == keys::CHANGE_STATE && !switchedState)
                {
                    stateMan->pushState(new GameState());
                    switchedState = true;
                }
            }
            cameraMan->move(addX, addY);

            frameTime -= cStep;
            t += cStep; //Current time period;
        }

        stateMan->render();
    }

    return 0;
}
