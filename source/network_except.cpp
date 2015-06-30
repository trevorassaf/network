#include "../headers/network_except.h"

#include <string.h>
#include <string>

Network::Exception::BadIpv4Address::BadIpv4Address(
  int error_code,
  const std::string & bad_ipv4
) : 
  _errorCode(error_code),
  _badIpv4(bad_ipv4)
{}

const char * Network::Exception::BadIpv4Address::what() const throw() {
  std::string error_message = std::string("[Bad ipv4: ") + _badIpv4
      + std::string(", error message: ")
      + std::string(::strerror(_errorCode));
  return error_message.c_str();
}

Network::Exception::BadPortString::BadPortString(
    const std::string & bad_port
) : 
    _badPort(bad_port)
{}

const char * Network::Exception::BadPortString::what() const throw() {
  std::string error_message = std::string("[Bad port: ")
      + std::to_string(_badPort)
      + std::string("]");
  return error_message.c_str();
}
