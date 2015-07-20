#include "../../../headers/domain/ip/port_builder.h"

#include "../../../headers/network_except.h"

#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string>

void Network::PortBuilder::validateOrThrow() const {
  if (_hasPort) {
    throw std::runtime_error("Must specify port number before building port."); 
  }
}

Network::PortBuilder::PortBuilder() : _hasPort(false) {}

Network::PortBuilder & Network::PortBuilder::setPort(uint16_t port) {
  _port = htons(port);
  _hasPort = true;
  return *this;
}

Network::PortBuilder & Network::PortBuilder::setPort(const std::string & port_str) {
  try {
    _port = static_cast<uint16_t>(std::stoul(port_str));
  } catch (...) {
    throw Network::Exception::BadPortString(port_str);
  }
  return *this;
}

const Network::Port Network::PortBuilder::build() const {
  validateOrThrow(); 
  return Network::Port(_port);
}

const Network::Port * Network::PortBuilder::buildNew() const {
  validateOrThrow(); 
  return new Network::Port(_port);
}
