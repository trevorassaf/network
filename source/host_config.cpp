#include "../headers/host_config.h"

#include <cassert>
#include <netinet/in.h>
#include <sys/socket.h>
#include <stdexcept>

const Network::HostConfig::AddressFamilyMap Network::HostConfig::ADDRESS_FAMILY_MAP = {
  {Network::HostConfig::AddressType::IPV4, AF_INET},
  {Network::HostConfig::AddressType::IPV6, AF_INET6},
  {Network::HostConfig::AddressType::UNSPECIFIED, AF_UNSPEC}
};

const Network::HostConfig::ReverseAddressFamilyMap Network::HostConfig::REVERSE_ADDRESS_FAMILY_MAP = {
  {AF_INET, Network::HostConfig::AddressType::IPV4},
  {AF_INET6, Network::HostConfig::AddressType::IPV6},
  {AF_UNSPEC, Network::HostConfig::AddressType::UNSPECIFIED}
};

Network::HostConfig::HostConfig() :
    _addressType(Network::HostConfig::AddressType::UNSPECIFIED),
    _hasAddress(false),
    _hasPort(false)
{}

bool Network::HostConfig::hasAddress() const {
  return _hasAddress;
}

bool Network::HostConfig::hasPort() const {
  return _hasPort;
}

Network::HostConfig & Network::HostConfig::setIpv4(const Network::Ipv4 & ipv4) {
  _ipv4 = ipv4;
  _hasAddress = true;
  setIpv4();
  return *this;
}

Network::HostConfig & Network::HostConfig::setIpv6(const Network::Ipv6 & ipv6) {
  _ipv6 = ipv6;
  _hasAddress = true;
  setIpv6();
  return *this;
}

Network::HostConfig & Network::HostConfig::setPort(const Network::Port & port) {
  _port = port;
  _hasPort = true;
  return *this;
}

Network::HostConfig & Network::HostConfig::unsetAddress() {
  _addressType = Network::HostConfig::AddressType::UNSPECIFIED; 
  return *this;
}

Network::HostConfig & Network::HostConfig::unsetPort() {
  _hasPort = false;
  return *this;
}

Network::HostConfig & Network::HostConfig::setIpv4() {
  _addressType = Network::HostConfig::AddressType::IPV4;
  return *this;
}

Network::HostConfig & Network::HostConfig::setIpv6() {
  _addressType = Network::HostConfig::AddressType::IPV6;
  return *this;
}

Network::HostConfig & Network::HostConfig::setAddressUnspecified() {
  _addressType = Network::HostConfig::AddressType::UNSPECIFIED;
  _hasAddress = false;
  return *this;
}

Network::HostConfig::AddressType Network::HostConfig::getAddressType() const {
  return _addressType;
}

const Network::Ipv4 & Network::HostConfig::getIpv4() const {
  if (_addressType == Network::HostConfig::AddressType::IPV4) {
    throw std::runtime_error("Ipv4 not set! Must check with getAddressType() == IPV4");
  }
  return _ipv4;
}

const Network::Ipv6 & Network::HostConfig::getIpv6() const {
  if (_addressType == Network::HostConfig::AddressType::IPV6) {
    throw std::runtime_error("Ipv6 not set! Must check with getAddressType() == IPV6");
  }
  return _ipv6;
}

const Network::Port & Network::HostConfig::getPort() const {
  if (!_hasPort) {
    throw std::runtime_error("Port not set! Must check with hasPort()");
  }
  return _port;
}

int Network::HostConfig::getAddressFamily() const {
  return Network::HostConfig::ADDRESS_FAMILY_MAP.at(_addressType);
}
