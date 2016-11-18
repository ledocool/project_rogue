#include "core/appcore.h"

int main(int argc __attribute__((unused)) , char **argv __attribute__((unused)) )
{
    try
    {
        AppCore app;
        app.start();

        return 0;
    }
    catch(Exception e)
    {
        //TODO: log exception message;
        return e.getErrorCode();
    }
}

