#pragma once

#include "network_namespace.h"
#include <stdexcept>

class Network::NetworkException : std::runtime_error {
  public:
    NetworkException(const std::string & error_string);
};
