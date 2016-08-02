#include "sound.h"

sound::sound()
{
}

sound::sound(const char *filepath)
{
    load(filepath);
}

sound::~sound()
{
    kill();
}

bool sound::load(const char *filepath)
{
    chunk = Mix_LoadWAV (filepath);
    name = filepath;

    if(chunk == NULL)
        return false;

    //singleton <audioManager>::get()->regSound(this);
    return true;
}

void sound::reload()
{
    load(name.c_str());
}

void sound::kill()
{
    Mix_FreeChunk(chunk);
}

void sound::setVolume(int v)
{
    if (v > MIX_MAX_VOLUME)
        vol = MIX_MAX_VOLUME;
    else
        vol = v;

    prev_vol = Mix_VolumeChunk(chunk, v);
}

Mix_Chunk *sound::getSound()
{
    return chunk;
}
