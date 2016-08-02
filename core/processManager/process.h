#ifndef PROCESS_H
#define PROCESS_H

#include "stdafx.h"

class process
{
public:
    process()
    {
       _is_running = false;
       _pid = -1;

    }
    virtual ~process(){}

    virtual void run () = 0;  //Asks process to startt;
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

class menuProcess : public process
{
public:
    menuProcess() : process() {}

    void run () { printf ("Imma running game\n"); }
    void pause () { printf ("Imma pausing game\n"); }
    void resume () { printf ("Imma resuming game\n"); }
    void stop () { printf("Imma stopping game\n"); }

};

#endif // PROCESS_H
