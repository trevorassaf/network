#include "port.h"

Namespace::Ip::Port::Port(uint16_t port_number) :
    _portNumber(port_number) {}

uint16_t Network::Ip::Port::getPortNumber() const {
  return _portNumber;
}

const std::string Network::Ip::Port::toString() const {
  return std::to_string(_portNumber);
}
