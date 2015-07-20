#include "../../../headers/domain/ip/port.h"

#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string>

Network::Port::Port(uint16_t port) : _port(port) {}

uint16_t Network::Port::getNumber() const {
  return _port;
}

const std::string Network::Port::toString() const {
  return std::to_string(ntohs(_port));
}
