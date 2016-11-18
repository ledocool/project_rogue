#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include "stdafx.h"

class sound;
class music;

class AudioManager
{
public:
    AudioManager();
    ~AudioManager();

    bool regSound(sound *snd);
    bool unregRound(sound *snd);

    bool regMusic(music *snd);
    bool unregMusic(music *snd);

private:
    std::vector <sound *> _sound_array;
    std::vector <music *> _music_array;
};

#endif // AUDIOMANAGER_H
