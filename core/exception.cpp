#include "exception.h"

Exception::Exception()
{
    exceptionMessage = "";
    errorcode = errorCodes::noError;
}

Exception::Exception(std::string message, errorCodes::errorCodes errorcode)
{
    this->exceptionMessage = message;
    this->errorcode = errorcode;
}

Exception::Exception(const char *message, errorCodes::errorCodes errorcode)
{
    std::string msg = message;
    Exception(msg, errorcode);
}

std::string Exception::getMessage()
{
    return exceptionMessage;
}

int Exception::getErrorCode()
{
    return errorcode;
}

