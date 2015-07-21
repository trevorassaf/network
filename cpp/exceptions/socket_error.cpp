#include "exceptions_namespace.h"

#include <string.h>
#include <string>

#include <netdb.h>

const char * Network::SocketError::what() const throw() {
  std::string error_string = _errorMessage;
  for (int error_number : _errorNumbers) {
    error_string += std::string("Error: ") + std::string(::strerror(error_number)) + std::string("\n");
  }
  return error_string.c_str();
}
