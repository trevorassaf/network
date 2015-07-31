#include "socket_initialization_exception_builder.h"

Network::Linux::SocketInitializationExceptionBuilder::SocketInitializationExceptionBuilder()
    : _errorStrings() {}

void Network::Linux::SocketInitializationExceptionBuilder::pushErrorString(
    const std::string & error_string
) {
  _errorStrings.push_back(error_string);
}

const Network::Linux::SocketInitializationException
Network::Linux::SocketInitializationExceptionBuilder::build() const {
  return Network::Linux::SocketInitializationException(_errorStrings);
}
