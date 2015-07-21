#include "ip_address_string_error.h"

#include <string.h>
#include <string>

#include <netdb.h>

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
