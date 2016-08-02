#ifndef KEYBOARDENQUIRYPROCESS_H
#define KEYBOARDENQUIRYPROCESS_H
#include "core/processManager/process.h"
#include "stdafx.h"

class keyboardEnquiryProcess : public process
{
    inputManager *iMan;

    keyboardEnquiryProcess() : process()
    {
        iMan = singleton <inputManager>::get();
    }

    void run()
    {

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


#endif // KEYBOARDENQUIRYPROCESS_H
