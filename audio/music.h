#ifndef MUSIC_H
#define MUSIC_H

#include "stdafx.h"
#include "audio/audiomanager.h"

class Music
{
public:
    Music();
    Music(const char *filepath);
    ~Music();
    bool load(const char *filepath); //load sound
    void reload(); //reload
    void kill(); //unload sound

    Mix_Music *getMusic();

private:
    Mix_Music *chunk;
    std::string name;
};

#endif // MUSIC_H
