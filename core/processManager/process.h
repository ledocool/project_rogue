#ifndef PROCESS_H
#define PROCESS_H

#include "stdafx.h"

class Process
{
public:
    Process()
    {
       _is_running = false;
       _pid = -1;
    }
    virtual ~Process(){}

    virtual void run () = 0;  //Asks process to start;
    virtual void resume () = 0; //Asks process to continue
    virtual void pause() = 0; //Asks process to pause
    virtual void stop () = 0; //Asks process to stop


    bool isRunning () { return _is_running; }
    bool isPaused () { return !(_is_running); }
    unsigned int getPid () { return _pid; }
    void setPid ( unsigned int p ) { _pid = p; }

private:
    bool _is_running;
    unsigned int _pid;

};

#endif // PROCESS_H
