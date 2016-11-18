#ifndef AUDIOMIXER_H
#define AUDIOMIXER_H

#include "stdafx.h"

class AudioMixer
{
public:
    AudioMixer();
    bool init();
    void free();

    void setChannels(int quantity);

    void playSound(sound *s, int channel = -1); //Selects first unused channel by default
    void playLoop(sound *s, int channel = -1);
    void playMusic(music *m);
    void playLoop(music *m);

    uint getChannelsQuantity();

private:
    uint _channelsNum; //Number of mixing channels

};

#endif // AUDIOMIXER_H
