#include "audiomanager.h"

AudioManager::AudioManager()
{
}

AudioManager::~AudioManager()
{
    for(uint i=0; i<_sound_array.size(); i++)
        delete _sound_array[i];
    for(uint i=0; i<_music_array.size(); i++)
        delete _music_array[i];
}

bool AudioManager::regSound(sound *snd)
{
    for(uint i=0; i<_sound_array.size(); i++)
        if(_sound_array[i] == snd)
            return false;

    _sound_array.push_back(snd);
    return true;
}

bool AudioManager::unregRound(sound *snd)
{
    for(uint i=0; i<_sound_array.size(); i++)
        if(_sound_array[i] == snd)
        {
            sound *s = _sound_array[i];
            _sound_array.erase(_sound_array.begin()+i);
            delete s;

            return true;
        }

    return false;
}

bool AudioManager::regMusic(music *snd)
{
    for(uint i=0; i<_music_array.size(); i++)
        if(_music_array[i] == snd)
            return false;

    _music_array.push_back(snd);
    return true;
}

bool AudioManager::unregMusic(music *snd)
{
    for(uint i=0; i<_music_array.size(); i++)
        if(_music_array[i] == snd)
        {
            music *s = _music_array[i];
            _music_array.erase(_music_array.begin()+i);
            delete s;

            return true;
        }

    return false;
}
