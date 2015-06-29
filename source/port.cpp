#include "../headers/port.h"

#include <arpa/inet.h>

const Network::Port Network::Port::buildFromHostByteOrderNumber(uint16_t port_num) {
  return Network::Port(port_num);
}

const Network::Port Network::Port::buildFromNetworkByteOrderNumber(uint16_t port_num) {
  return Network::Port(ntohs(port_num));
}

const Network::Port Network::Port::buildFromString(const std::string & port_str) {
  uint16_t port_num = ::static_cast<uint16_t>(std::stoul(port_str));
  return Network::Port(port_num);
}
