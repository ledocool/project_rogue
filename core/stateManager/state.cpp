#include "state.h"

State::State()
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

State::~State()
{

}
