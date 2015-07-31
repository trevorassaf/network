#include "address_builder.h"

#include <ip/address.h>

#include <stdexcept>

Network::Ip::AddressBuilder::AddressBuilder() : _hasAddressString(false) {}

Network::Ip::AddressBuilder::AddressBuilder(
    const Network::Ip::Address & address    
) {
  from(address); 
}

Network::Ip::AddressBuilder &
Network::Ip::AddressBuilder::setAddressString(
    const std::string & address_string
) {
  _addressString = address_string;
  _hasAddressString = true;
  return *this;
}

Network::Ip::AddressBuilder &
Network::Ip::AddressBuilder::from(
    const Network::Ip::Address & address
) {
  _hasAddressString = true;
  _addressString = address.getAddressString();
  return *this;
}

const Network::Ip::Address Network::Ip::AddressBuilder::build() const {
  if (!_hasAddressString) {
    throw std::runtime_error("Must set address string before building!");
  } 
  return Network::Ip::Address(_addressString);
}
