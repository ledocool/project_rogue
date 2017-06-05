#ifndef EXCEPTION_H
#define EXCEPTION_H

#include "stdafx.h"

namespace errorCodes {
    enum errorCodes
    {
        noError = 0,
        graphicInitError,
        stateError
    };
}

class BasicException
{
public:
    BasicException(std::string message, errorCodes::errorCodes errorcode);
    BasicException(const char *message, errorCodes::errorCodes errorcode);

    const std::string getMessage() const;
    int getErrorCode();
    const char *what() const;

private:
    void init(std::string message, errorCodes::errorCodes errorcode);

    std::string exceptionMessage;
    errorCodes::errorCodes errorcode;
};

#endif // EXCEPTION_H
