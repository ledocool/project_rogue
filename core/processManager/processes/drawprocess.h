#ifndef DRAWPROCESS_H
#define DRAWPROCESS_H
#include "core/processManager/process.h"
#include "stdafx.h"

class drawProcess : public Process
{
    GraphicManager *gMan;

    drawProcess() : Process()
    {
       gMan = Singleton <GraphicManager>::get();
    }

    void run()
    {
        //gMan->render();
    }

    void pause ()
    {

    }

    void resume ()
    {

    }

    void stop ()
    {

    }
};


#endif // DRAWPROCESS_H
