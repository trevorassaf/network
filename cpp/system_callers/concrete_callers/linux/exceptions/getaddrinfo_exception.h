#pragma once

#include "exceptions_namespace.h"
#include "../../../abstract_callers/caller_modules/exceptions/network_exception.h"

class Network::Linux::GetAddrInfoException : Network::NetworkException {
 
  private:
    static const int VALID_CODE;

  public:
    static bool isError(int error_number);
    GetAddrInfoException(int error_number);
};
