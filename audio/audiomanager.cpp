#include "audiomanager.h"

audioManager::audioManager()
{
}

audioManager::~audioManager()
{
    for(uint i=0; i<sound_array.size(); i++)
        delete sound_array[i];
    for(uint i=0; i<music_array.size(); i++)
        delete music_array[i];
}

bool audioManager::regSound(sound *snd)
{
    for(uint i=0; i<sound_array.size(); i++)
        if(sound_array[i] == snd)
            return false;

    sound_array.push_back(snd);
    return true;
}

bool audioManager::unregRound(sound *snd)
{
    for(uint i=0; i<sound_array.size(); i++)
        if(sound_array[i] == snd)
        {
            sound *s = sound_array[i];
            sound_array.erase(sound_array.begin()+i);
            delete s;

            return true;
        }

    return false;
}

bool audioManager::regMusic(music *snd)
{
    for(uint i=0; i<music_array.size(); i++)
        if(music_array[i] == snd)
            return false;

    music_array.push_back(snd);
    return true;
}

bool audioManager::unregMusic(music *snd)
{
    for(uint i=0; i<music_array.size(); i++)
        if(music_array[i] == snd)
        {
            music *s = music_array[i];
            music_array.erase(music_array.begin()+i);
            delete s;

            return true;
        }

    return false;
}
