#ifndef PROCESSMANAGER_H
#define PROCESSMANAGER_H

#include "stdafx.h"
#include "core/processManager/process.h"

class processManager// : public singleton <processManager>
{
public:
    processManager();
    ~processManager();

    int pushProc ( process *p ); //Adds another process to the end
    bool popProc (unsigned int id, process *p); //Kill process by its and returns link to process through *p;
    void popAll ();
    bool run();

private:
    std::vector <process *> processQueue;
    unsigned int procLimit;

};

#endif // PROCESSMANAGER_H
