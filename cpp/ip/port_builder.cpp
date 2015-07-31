#include "port_builder.h"

#include <ip/port.h>

#include <stdexcept> 

Network::Ip::PortBuilder::PortBuilder() : _hasPortNumber(false) {}

Network::Ip::PortBuilder::PortBuilder(
    const Network::Ip::Port & port    
) {
  from(port);
}

Network::Ip::PortBuilder & Network::Ip::PortBuilder::setPortNumber(uint16_t port_number) {
  _portNumber = port_number;
  _hasPortNumber = true;
  return *this;
}

Network::Ip::PortBuilder &
Network::Ip::PortBuilder::setPortNumber(
    const std::string & port_number_string
) {
  _portNumber = std::stoul(port_number_string);
  _hasPortNumber = true;
  return *this;
}

Network::Ip::PortBuilder &
Network::Ip::PortBuilder::from(const Network::Ip::Port & port) {
  _portNumber = port.getPortNumber();
  _hasPortNumber = true;
  return *this;
}

const Network::Ip::Port Network::Ip::PortBuilder::build() const {
  if (!_hasPortNumber) {
    throw std::runtime_error("Must set port number before building port!");
  }
  return Network::Ip::Port(_portNumber);
}
