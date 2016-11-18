#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

namespace errorCodes {
    enum errorCodes
    {
        noError = 0,
        graphicInitError,
        stateError
    };
}

class Exception
{
public:
    Exception();
    Exception(std::string message, errorCodes::errorCodes errorcode);
    Exception(const char *message, errorCodes::errorCodes errorcode);

    std::string getMessage();
    int getErrorCode();

private:
    std::string exceptionMessage;
    errorCodes::errorCodes errorcode;
};

#endif // EXCEPTION_H
