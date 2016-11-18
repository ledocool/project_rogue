#include "processmanager.h"

ProcessManager::ProcessManager()
{
    procLimit = 100;
}

ProcessManager::~ProcessManager()
{
    popAll();
}

int ProcessManager::pushProc(Process *p)
{
    if( processQueue.size() >= procLimit )
        return -1; //Means epic failure;

    p->setPid( processQueue.size() + 1 ); //Easy way to get pids running
    processQueue.push_back(p);
    return p->getPid();
}

bool ProcessManager::popProc(unsigned int id, Process *p __attribute__ ((unused)) )
{
    for(unsigned int i=0; i<processQueue.size(); i++)
    {
        if ( processQueue[i]->getPid() == id )
        {
            p = processQueue[i];
            processQueue.erase(processQueue.begin() + i);
            return true;
        }
    }
    return false; //no pid found
}

void ProcessManager::popAll()
{
    Process *p;
    for(int i = processQueue.size()-1; i>=0; i--)
    {
        processQueue.back()->stop();
        p = processQueue.back();
        processQueue.pop_back();
        delete p;
    }
}

bool ProcessManager::run()
{
    if( processQueue.empty() )
        return false; //No process to run;

    for(unsigned int i=0; i<processQueue.size(); i++)
    {
        processQueue[i]->run();
    }
    return true;
}
