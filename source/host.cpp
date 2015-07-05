#include "../headers/host.h"

#include <cassert>
#include <netinet/in.h>
#include <sys/socket.h>
#include <stdexcept>

const Network::Host::AddressFamilyMap Network::Host::ADDRESS_FAMILY_MAP = {
  {Network::Host::AddressType::IPV4, AF_INET},
  {Network::Host::AddressType::IPV6, AF_INET6},
};

const Network::Host::ReverseAddressFamilyMap Network::Host::REVERSE_ADDRESS_FAMILY_MAP = {
  {AF_INET, Network::Host::AddressType::IPV4},
  {AF_INET6, Network::Host::AddressType::IPV6},
};

Network::Host::Host(const Network::Ipv4 & ipv4, const Network::Port & port) : 
    _addressType(Network::Host::AddressType::IPV4),
    _ipv4(ipv4),
    _ipv6(ipv4),
    _port(port)
{}

Network::Host::Host(const Network::Ipv6 & ipv6, const Network::Port & port) : 
    _addressType(Network::Host::AddressType::IPV6),
    _ipv6(ipv6),
    _port(port)
{}

Network::Host::AddressType Network::Host::getAddressType() const {
  return _addressType;
}

const Network::Ipv4 & Network::Host::getIpv4() const {
  if (_addressType != Network::Host::AddressType::IPV4) {
    throw std::runtime_error("Host not using ipv4! Check getAddressType()");
  }
  return _ipv4;
}

const Network::Ipv6 & Network::Host::getIpv6() const {
  return _ipv6;
}

const Network::Port & Network::Host::getPort() const {
  return _port;
}

int Network::Host::getAddressFamily() const {
  return Network::Host::ADDRESS_FAMILY_MAP.at(_addressType);
}

bool Network::Host::operator==(const Network::Host & host) {
  if (_addressType != host._addressType || _port != host._port) {
    return false;
  } 

  switch (_addressType) {
    case Network::Host::AddressType::IPV4:
      return _ipv4 == host._ipv4;
    case Network::Host::AddressType::IPV6:
      return _ipv6 == host._ipv6;
    default:
      throw std::runtime_error(
          std::string("Unknown AddressType: ") +
          std::to_string(static_cast<int>(_addressType))
      );
  }
}

bool Network::Host::operator!=(const Network::Host & host) {
  return !(*this == host);
}
