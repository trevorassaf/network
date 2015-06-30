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
    {}
