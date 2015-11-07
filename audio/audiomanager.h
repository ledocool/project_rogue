#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include "stdafx.h"

class sound;
class music;

class audioManager
{
public:
    audioManager();
    ~audioManager();

    bool regSound(sound *snd);
    bool unregRound(sound *snd);

    bool regMusic(music *snd);
    bool unregMusic(music *snd);

private:
    std::vector <sound *> sound_array;
    std::vector <music *> music_array;
};

#endif // AUDIOMANAGER_H
