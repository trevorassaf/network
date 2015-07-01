#include "../headers/network_except.h"

#include <string.h>
#include <string>

const std::string Network::Exception::NetworkRuntimeError::composeErrorMessage(
    int error_number,
    const std::string & user_error_str
) {
  return std::string("[user error message") 
      + user_error_str
      + std::string(", system error message: ")
      + ::strerror(error_number)
      + std::string("]");
}

Network::Exception::NetworkRuntimeError::NetworkRuntimeError(
    int error_number,
    const std::string & error_str
) : 
    std::runtime_error(
        Network::Exception::NetworkRuntimeError::composeErrorMessage(
            error_number,
            error_str
        )
    )
{}

Network::Exception::NetworkRuntimeError::NetworkRuntimeError(
    const std::string & error_str
) : 
    std::runtime_error(error_str)
{}

Network::Exception::NetworkRuntimeError::NetworkRuntimeError(
    int error_number
) : 
    std::runtime_error(::strerror(error_number))
{}

const Network::Exception::BadIpAddressString::ip_version_map 
    Network::Exception::BadIpAddressString::IP_VERSIONS = 
        std::unordered_map<int, const std::string>{
            {AF_INET, "Ipv4"},
            {AF_INET6, "Ipv6"}
        };

Network::Exception::BadIpAddressString::BadIpAddressString(
    int ip_version,
    const std::string & bad_ip
) : 
    _ipVersion(ip_version),
    _badIp(bad_ip)
{}

const char * Network::Exception::BadIpAddressString::what() const throw() {
  std::string error_message = std::string("[Bad ip address string: ") 
      + _badIp 
      + std::string(", version: ")
      + Network::Exception::BadIpAddressString::IP_VERSIONS.at(_ipVersion)
      + std::string("]");
  return error_message.c_str();
}

Network::Exception::BadPortString::BadPortString(
    const std::string & bad_port
) : 
    _badPort(bad_port)
{}

const char * Network::Exception::BadPortString::what() const throw() {
  std::string error_message = std::string("[Bad port string: ")
      + _badPort
      + std::string("]");
  return error_message.c_str();
}
