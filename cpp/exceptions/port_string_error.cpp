#include "port_string_error.h"

#include <string.h>
#include <string>

#include <netdb.h>

Network::PortStringError::PortStringError(
    const std::string & bad_port
) : 
    _badPort(bad_port)
{}

const char * Network::PortStringError::what() const throw() {
  std::string error_message = std::string("[Bad port string: ")
      + _badPort
      + std::string("]");
  return error_message.c_str();
}
