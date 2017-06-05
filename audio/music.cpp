#include "music.h"

Music::Music()
{
}

Music::Music(const char *filepath)
{
    load(filepath);
}

Music::~Music()
{
    kill();
}

bool Music::load(const char *filepath)
{
    chunk = Mix_LoadMUS (filepath);
    name = filepath;

    if(chunk == NULL)
        return false;

    //singleton <audioManager>::get()->regMusic(this);
    return true;
}

void Music::reload()
{
    load(name.c_str());
}

void Music::kill()
{
    Mix_FreeMusic(chunk);
}

Mix_Music *Music::getMusic()
{
    return chunk;
}

