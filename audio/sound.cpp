#include "sound.h"

Sound::Sound()
{
}

Sound::Sound(const char *filepath)
{
    load(filepath);
}

Sound::~Sound()
{
    kill();
}

bool Sound::load(const char *filepath)
{
    chunk = Mix_LoadWAV (filepath);
    name = filepath;

    if(chunk == NULL)
        return false;

    //singleton <audioManager>::get()->regSound(this);
    return true;
}

void Sound::reload()
{
    load(name.c_str());
}

void Sound::kill()
{
    Mix_FreeChunk(chunk);
}

void Sound::setVolume(int v)
{
    if (v > MIX_MAX_VOLUME)
        vol = MIX_MAX_VOLUME;
    else
        vol = v;

    prev_vol = Mix_VolumeChunk(chunk, v);
}

Mix_Chunk *Sound::getSound()
{
    return chunk;
}
