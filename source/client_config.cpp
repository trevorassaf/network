#include "../headers/client_config.h"

#include <cassert>
#include <netinet/in.h>
#include <sys/socket.h>
#include <stdexcept>

const Network::ClientConfig::AddressFamilyMap Network::ClientConfig::ADDRESS_FAMILY_MAP = {
  {Network::ClientConfig::AddressType::IPV4, AF_INET},
  {Network::ClientConfig::AddressType::IPV6, AF_INET6},
  {Network::ClientConfig::AddressType::UNSPECIFIED, AF_UNSPEC}
};

const Network::ClientConfig::ReverseAddressFamilyMap Network::ClientConfig::REVERSE_ADDRESS_FAMILY_MAP = {
  {AF_INET, Network::ClientConfig::AddressType::IPV4},
  {AF_INET6, Network::ClientConfig::AddressType::IPV6},
  {AF_UNSPEC, Network::ClientConfig::AddressType::UNSPECIFIED}
};

Network::ClientConfig::ClientConfig() :
    _addressType(Network::ClientConfig::AddressType::UNSPECIFIED),
    _hasAddress(false),
    _hasPort(false)
{}

bool Network::ClientConfig::hasAddress() const {
  return _hasAddress;
}

bool Network::ClientConfig::hasPort() const {
  return _hasPort;
}

Network::ClientConfig & Network::ClientConfig::setIpv4(const Network::Ipv4 & ipv4) {
  _ipv4 = ipv4;
  _hasAddress = true;
  setIpv4();
  return *this;
}

Network::ClientConfig & Network::ClientConfig::setIpv6(const Network::Ipv6 & ipv6) {
  _ipv6 = ipv6;
  _hasAddress = true;
  setIpv6();
  return *this;
}

Network::ClientConfig & Network::ClientConfig::setPort(const Network::Port & port) {
  _port = port;
  _hasPort = true;
  return *this;
}

Network::ClientConfig & Network::ClientConfig::unsetAddress() {
  _addressType = Network::ClientConfig::AddressType::UNSPECIFIED; 
  return *this;
}

Network::ClientConfig & Network::ClientConfig::unsetPort() {
  _hasPort = false;
  return *this;
}

Network::ClientConfig & Network::ClientConfig::setIpv4() {
  _addressType = Network::ClientConfig::AddressType::IPV4;
  return *this;
}

Network::ClientConfig & Network::ClientConfig::setIpv6() {
  _addressType = Network::ClientConfig::AddressType::IPV6;
  return *this;
}

Network::ClientConfig & Network::ClientConfig::setAddressUnspecified() {
  _addressType = Network::ClientConfig::AddressType::UNSPECIFIED;
  _hasAddress = false;
  return *this;
}

Network::ClientConfig::AddressType Network::ClientConfig::getAddressType() const {
  return _addressType;
}

const Network::Ipv4 & Network::ClientConfig::getIpv4() const {
  if (_addressType == Network::ClientConfig::AddressType::IPV4) {
    throw std::runtime_error("Ipv4 not set! Must check with getAddressType() == IPV4");
  }
  return _ipv4;
}

const Network::Ipv6 & Network::ClientConfig::getIpv6() const {
  if (_addressType == Network::ClientConfig::AddressType::IPV6) {
    throw std::runtime_error("Ipv6 not set! Must check with getAddressType() == IPV6");
  }
  return _ipv6;
}

const Network::Port & Network::ClientConfig::getPort() const {
  if (!_hasPort) {
    throw std::runtime_error("Port not set! Must check with hasPort()");
  }
  return _port;
}

int Network::ClientConfig::getAddressFamily() const {
  return Network::ClientConfig::ADDRESS_FAMILY_MAP.at(_addressType);
}
