#pragma once

#include "exceptions_namespace.h"

class Network::Linux::SocketOpenException : Network::NetworkException {

  private:
    static int ERROR_CODE;       

  public:
    static bool isError(int error_code);
    static const std::string getErrorString(int error_code);
    SocketOpenException(int error_code);
};
