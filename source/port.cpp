#include "../../../headers/port.h"

#include "../headers/network_except.h"

#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>

const std::string Network::Port::stringifyPort(uint16_t port_number) {
  return std::to_string(ntohs(port_number));
}

uint16_t Network::Port::decodePort(const std::string & port_str) {
  try {
    uint16_t port_num = static_cast<uint16_t>(std::stoul(port_str)); // host-byte order
    return htons(port_num);
  } catch (...) {
    throw Network::Exception::BadPortString(port_str); 
  }
}

Network::Port::Port() : 
    _portNumber(DYNAMIC_PORT_NUMBER),
    _portString(Network::Port::stringifyPort(_portNumber))
{}

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

Network::Port::Port(const std::string & port_str) :
    _portNumber(Network::Port::decodePort(port_str)),
    _portString(port_str)
{}

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

bool Network::Port::isStatic() const {
  return _portNumber != DYNAMIC_PORT_NUMBER;
}
