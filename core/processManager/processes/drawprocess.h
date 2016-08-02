#ifndef DRAWPROCESS_H
#define DRAWPROCESS_H
#include "core/processManager/process.h"
#include "stdafx.h"

class drawProcess : public process
{
    graphicManager *gMan;

    drawProcess() : process()
    {
       gMan = singleton <graphicManager>::get();
    }

    void run()
    {
        gMan->render();
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
