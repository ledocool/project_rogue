#ifndef AUDIOMIXER_H
#define AUDIOMIXER_H

#include "stdafx.h"
#include "audio/sound.h"
#include "audio/music.h"

class AudioMixer
{
public:
    AudioMixer();
    bool init();
    void free();

    void setChannels(int quantity);

    void playSound(Sound *s, int channel = -1); //Selects first unused channel by default
    void playLoop(Sound *s, int channel = -1);
    void playMusic(Music *m);
    void playLoop(Music *m);

    uint getChannelsQuantity();

private:
    uint _channelsNum; //Number of mixing channels

};

#endif // AUDIOMIXER_H
