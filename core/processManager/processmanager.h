#ifndef PROCESSMANAGER_H
#define PROCESSMANAGER_H

#include "stdafx.h"
#include "core/processManager/process.h"

class ProcessManager
{
public:
    ProcessManager();
    ~ProcessManager();

    int pushProc ( Process *p ); //Adds another process to the end
    bool popProc (unsigned int id, Process *p); //Kill process by its and returns link to process through *p;
    void popAll ();
    bool run();

private:
    std::vector <Process *> processQueue;
    unsigned int procLimit;

};

#endif // PROCESSMANAGER_H
