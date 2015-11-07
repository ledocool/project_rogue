#include "processmanager.h"

processManager::processManager()
{
    procLimit = 100;
}

processManager::~processManager()
{
    popAll();
}

int processManager::pushProc(process *p)
{
    if( processQueue.size() >= procLimit )
        return -1; //Means epic failure;

    p->setPid( processQueue.size() + 1 ); //Easy way to get pids running
    processQueue.push_back(p);
    return p->getPid();
}

bool processManager::popProc(unsigned int id, process *p)
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

void processManager::popAll()
{
    process *p;
    for(int i = processQueue.size()-1; i>=0; i--)
    {
        processQueue.back()->stop();
        p = processQueue.back();
        processQueue.pop_back();
        delete p;
    }
}

bool processManager::run()
{
    if( processQueue.empty() )
        return false; //No process to run;

    for(unsigned int i=0; i<processQueue.size(); i++)
    {
        processQueue[i]->run();
    }
    return true;
}
