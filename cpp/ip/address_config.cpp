#include "address_config.h"

#include <stdexcept>

Network::Ip::AddressConfig::AddressConfig() : _address(nullptr) {}

Network::Ip::AddressConfig::AddressConfig(
    const Network::Ip::Address & address    
) :
    _address(new Network::Ip::Address(address))
{}

Network::Ip::AddressConfig::~AddressConfig() {
  delete _address;
  _address = nullptr;
}

bool Network::Ip::AddressConfig::hasAddress() const {
  return _address;
}

const Network::Ip::Address & Network::Ip::AddressConfig::getAddress() const {
  if (!hasAddress()) {
    throw std::runtime_error("Must set address config before calling getAddress()");
  }
  return *_address;
}
