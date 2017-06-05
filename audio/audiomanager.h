#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include "stdafx.h"

class Sound;
class Music;

class AudioManager
{
public:
    AudioManager();
    ~AudioManager();

    bool regSound(Sound *snd);
    bool unregRound(Sound *snd);

    bool regMusic(Music *snd);
    bool unregMusic(Music *snd);

private:
    std::vector <Sound *> _sound_array;
    std::vector <Music *> _music_array;
};

#endif // AUDIOMANAGER_H
