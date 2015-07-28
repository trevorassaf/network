#pragma once

#include "linux_exceptions.h"

#include <vector>
#include <string>

class Network::Linux::SocketInitializationExceptionBuilder : Network::Linux::NetworkException {

  private:
    std::vector<const std::string> _errorStrings;

  public:
    SocketInitialExceptionBuilder();
    void pushErrorString(const std::string & error_string);
    const Network::Linux::SocketInitializationException build() const;
};
