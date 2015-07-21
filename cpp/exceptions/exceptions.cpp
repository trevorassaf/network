#include "exceptions.h"

#include <string.h>
#include <string>

#include <netdb.h>

const std::string Network::NetworkRuntimeError::composeErrorMessage(
    int error_number,
    const std::string & user_error_str
) {
  return std::string("[user error message") 
      + user_error_str
      + std::string(", system error message: ")
      + ::strerror(error_number)
      + std::string("]");
}

Network::NetworkRuntimeError::NetworkRuntimeError(
    int error_number,
    const std::string & error_str
) : 
    std::runtime_error(
        Network::NetworkRuntimeError::composeErrorMessage(
            error_number,
            error_str
        )
    )
{}

Network::NetworkRuntimeError::NetworkRuntimeError(
    const std::string & error_str
) : 
    std::runtime_error(error_str)
{}

Network::NetworkRuntimeError::NetworkRuntimeError(
    int error_number
) : 
    std::runtime_error(::strerror(error_number))
{}

const Network::IpAddressStringError::ip_version_map 
    Network::IpAddressStringError::IP_VERSIONS = 
        std::unordered_map<int, const std::string>{
            {AF_INET, "Ipv4"},
            {AF_INET6, "Ipv6"}
        };

Network::IpAddressStringError::IpAddressStringError(
    int ip_version,
    const std::string & bad_ip
) : 
    _ipVersion(ip_version),
    _badIp(bad_ip)
{}

const char * Network::IpAddressStringError::what() const throw() {
  std::string error_message = std::string("[Bad ip address string: ") 
      + _badIp 
      + std::string(", version: ")
      + Network::IpAddressStringError::IP_VERSIONS.at(_ipVersion)
      + std::string("]");
  return error_message.c_str();
}

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

Network::GetAddrInfoError::GetAddrInfoError(int error_code) : _errorCode(error_code) {}

const char * Network::GetAddrInfoError::what() const throw() {
  return ::gai_strerror(_errorCode);
}

Network::SocketError::SocketError(
    const std::string & error_message,
    const std::vector<int> error_numbers
) : 
    _errorMessage(error_message),
    _errorNumbers(error_numbers)
{}

const char * Network::SocketError::what() const throw() {
  std::string error_string = _errorMessage;
  for (int error_number : _errorNumbers) {
    error_string += std::string("Error: ") + std::string(::strerror(error_number)) + std::string("\n");
  }
  return error_string.c_str();
}
