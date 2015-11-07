#include "core/appcore.h"

int main(int argc, char **argv)
{
    appCore app;
    app.init();
    app.start();
    app.finish();

    return 0;
}

