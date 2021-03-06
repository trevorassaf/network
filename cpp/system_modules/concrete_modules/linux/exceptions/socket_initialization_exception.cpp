#include "socket_initialization_exception.h"

const std::string Network::Linux::SocketInitializationException::serializeErrorStrings(
      const std::vector<std::string> & error_strings
) const {
  std::string serialize_error_string;

  for (const std::string & error_message : error_strings) {
    serialize_error_string += std::string("[") + error_message + std::string("]\n");
  }

  return serialize_error_string;
}

Network::Linux::SocketInitializationException::SocketInitializationException(
    const std::vector<std::string> & error_strings
) :
    Network::NetworkException(serializeErrorStrings(error_strings))
{}
