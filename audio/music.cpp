#include "music.h"

music::music()
{
}

music::music(const char *filepath)
{
    load(filepath);
}

music::~music()
{
    kill();
}

bool music::load(const char *filepath)
{
    chunk = Mix_LoadMUS (filepath);
    name = filepath;

    if(chunk == NULL)
        return false;

    //singleton <audioManager>::get()->regMusic(this);
    return true;
}

void music::reload()
{
    load(name.c_str());
}

void music::kill()
{
    Mix_FreeMusic(chunk);
}

Mix_Music *music::getMusic()
{
    return chunk;
}

