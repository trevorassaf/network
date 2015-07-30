#include "socket_initialization_exception.h"

const std::string Network::Linux::serializeErrorStrings(
      const std::vector<const std::string> error_strings
) const {
  std::string serialize_error_string;

  for (const std::string & error_message : error_strings) {
    serialize_error_string += std::to_string("[") + error_message + std::to_string("]\n");
  }

  return serialize_error_string;
}

Network::Linux::SocketInitializationException::SocketInitializationException(
    const std::vector<const std::string> & error_strings
) :
    Network::NetworkException(serializeErrorStrings(error_strings))
{}
