#ifndef LOADING_H
#define LOADING_H

#include "stdafx.h"
#include "state.h"

class loading : public State
{
public:
    loading();

    virtual void render ();
    virtual void processLogic (Uint32 elapsed);
    virtual void enter ();
    virtual void pause ();
    virtual void resume ();
    virtual void exit ();


private:
    std::string _levelName;
};

#endif // LOADING_H
