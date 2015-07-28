#include "socket_initialization_exception_builder.h"
#include "socket_initialization_exception.h"

Network::Linux::SocketInitialExceptionBuilder::SocketInitialExceptionBuilder() : _errorStrings() {}

void Network::Linux::SocketInitialExceptionBuilder::pushErrorString(const std::string & error_string) {
  _errorStrings.push_back(error_string);
}

const Network::Linux::SocketInitializationException build() const {
  return Network::Linux::SocketInitializationException(_errorStrings);
}
