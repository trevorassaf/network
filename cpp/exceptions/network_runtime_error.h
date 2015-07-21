#pragma once

#include "exceptions_namespace.h"

#include <stdexcept>
#include <string>
#include <arpa/inet.h>

class Network::NetworkRuntimeError : public std::runtime_error { 
  private:
    static const std::string composeErrorMessage(int error_number, const std::string & user_error_str);

  public:
    NetworkRuntimeError(int error_number, const std::string & error_str);
    NetworkRuntimeError(const std::string & error_str);
    NetworkRuntimeError(int error_number);
};
