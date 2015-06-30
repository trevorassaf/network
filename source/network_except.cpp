#include "../headers/network_except.h"

#include <string.h>

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
