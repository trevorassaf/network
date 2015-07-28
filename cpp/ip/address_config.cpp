#include "address_config.h"

#include <stdexcept>

Network::Ip::AddressConfig::AddressConfig() : _hasAddress(false) {}

Network::Ip::AddressConfig::AddressConfig(
    const Network::Ip::Address & address    
) :
    _hasAddress(true),
    _addressBuilder(address)
{}

bool Network::Ip::Address::hasAddress() const {
  return _hasAddress;
}

const Network::Ip::Address Network::Ip::AddressConfig::getAddress() const {
  if (!_hasAddress) {
    throw std::runtime_error("Must set address config before calling getAddress()");
  }
  return _addressBuilder.build();
}
