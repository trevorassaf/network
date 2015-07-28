#pragma once

#include "linux_exception.h"
#include <vector>
#include <string>

class Network::Linux::SocketInitializationException : Network::NetworkException {
  private:
    const std::string serializeErrorStrings() const; 

  public:
    NetworkException(const std::vector<const std::string> error_strings);
};
