#include "address.h"

Network::Ip::Address::Address(const std::string & address_string) :
    _addressString(address_string) {}

const std::string & Network::Ip::Address::getAddressString() const {
  return _addressString;
}
