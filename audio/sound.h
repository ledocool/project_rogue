#ifndef SOUND_H
#define SOUND_H

#include "stdafx.h"
#include "audio/audiomanager.h"

class sound
{
public:
    sound();
    sound(const char *filepath);
    ~sound();
    bool load(const char *filepath); //load sound
    void reload(); //reload
    void kill(); //unload sound

    void setVolume(int v);
    int getVolume();
    Mix_Chunk *getSound();

private:
    Mix_Chunk *chunk;
    std::string name;
    int prev_vol, vol;
};

#endif // SOUND_H
