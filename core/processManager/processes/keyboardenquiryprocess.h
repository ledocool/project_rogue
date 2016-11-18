#ifndef KEYBOARDENQUIRYPROCESS_H
#define KEYBOARDENQUIRYPROCESS_H
#include "core/processManager/process.h"
#include "stdafx.h"

class keyboardEnquiryProcess : public Process
{
    InputManager *iMan;

    keyboardEnquiryProcess() : Process()
    {
        iMan = Singleton <InputManager>::get();
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
