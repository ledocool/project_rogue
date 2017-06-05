#include "core/appcore.h"

int main(int argc __attribute__((unused)) , char **argv __attribute__((unused)) )
{
    try
    {
        AppCore app;
        app.start();

        return 0;
    }
    catch(BasicException &e)
    {
        std::cout << e.what() << std::endl;
        return e.getErrorCode();
    }
}

