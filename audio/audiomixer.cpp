#include "audiomixer.h"

AudioMixer::AudioMixer()
{
}

bool AudioMixer::init()
{
    if(SDL_InitSubSystem( SDL_INIT_AUDIO ))
    {
        std::cout << "Could not init audio:" << SDL_GetError() << std::endl;
        return false;
    }

    int flags = MIX_INIT_OGG | MIX_INIT_MP3;
    int inited = Mix_Init( flags );
    if((inited&flags) != flags)
    {
        std::cout << "Could not init audio mixer:" << SDL_GetError() << std::endl;
        return false;
    }

    if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 1, 1024) == -1)
    {
        std::cout << "Could not open audio device: " << SDL_GetError() << std::endl;
        return false;
    }

    setChannels(8); //Setting 8 channels by default;

    return true;
}

void AudioMixer::free()
{
    Mix_CloseAudio();
    Mix_Quit();
    SDL_QuitSubSystem(SDL_INIT_AUDIO);
}

void AudioMixer::setChannels(int quantity)
{
    _channelsNum = Mix_AllocateChannels(quantity);
}

void AudioMixer::playSound(Sound *s, int channel)
{
    if( Mix_PlayChannel(channel, s->getSound(), 0) == -1 )
        std::cout << "Unable to play sound: " << SDL_GetError() << std::endl;
}

void AudioMixer::playLoop(Sound *s, int channel)
{
    if( Mix_PlayChannel(channel, s->getSound(), -1) == -1 )
        std::cout << "Unable to play sound: " << SDL_GetError() << std::endl;
}

void AudioMixer::playMusic(Music *m)
{
    if( Mix_PlayMusic(m->getMusic(), 0) == -1)
        std::cout << "Unable to play music" << SDL_GetError() << std::endl;

}

void AudioMixer::playLoop(Music *m)
{
    if( Mix_PlayMusic(m->getMusic(), -1) == -1)
        std::cout << "Unable to play music" << SDL_GetError() << std::endl;
}

uint AudioMixer::getChannelsQuantity()
{
    return _channelsNum;
}
