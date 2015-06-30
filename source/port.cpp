#include "../headers/port.h"

#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>

const std::string Network::Port::stringifyPort(uint16_t port_number) {
  return std::to_string(ntohs(port_number));
}

Network::Port::Port(
    uint16_t port_number,
    const std::string & port_string
) :
    _portNumber(port_number),
    _portString(port_string)
{}

Network::Port::Port(
    uint16_t port_number
) : 
    _portNumber(port_number),
    _portString(Network::Port::stringifyPort(port_number))
{}

const Network::Port Network::Port::fromString(
    const std::string & port_string
) {
  uint16_t port_number;
  
  try {
    port_number = static_cast<uint16_t>(std::stoul(port_string)); // host-byte order
  } catch (...) {
    //throw Network::Exception::BadPortString(port_string); 
  }
  
  return Network::Port(htons(port_number), port_string);
}

uint16_t Network::Port::getNumber() const {
  return _portNumber;
}

const std::string & Network::Port::toString() const {
  return _portString;
}

bool Network::Port::operator==(const Network::Port & port) const {
  return _portNumber == port._portNumber;
}

bool Network::Port::operator!=(const Network::Port & port) const {
  return !(*this == port);
}
