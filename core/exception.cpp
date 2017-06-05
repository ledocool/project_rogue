#include "exception.h"

BasicException::BasicException(std::string message, errorCodes::errorCodes errorcode)
{
    init(message, errorcode);
}

BasicException::BasicException(const char *message, errorCodes::errorCodes errorcode)
{
    std::string msg = message;
    init(msg, errorcode);
}

const std::string BasicException::getMessage() const
{
    return exceptionMessage;
}

int BasicException::getErrorCode()
{
    return errorcode;
}

void BasicException::init(std::string message, errorCodes::errorCodes errorcode)
{
    this->exceptionMessage = message;
    this->errorcode = errorcode;
}


const char *BasicException::what() const
{
    return exceptionMessage.c_str();
}
