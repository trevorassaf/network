#include "port_config.h"

#include <stdexcept>

Network::Ip::PortConfig::PortConfig() : _port(nullptr) {}

Network::Ip::PortConfig::PortConfig(
    const Network::Ip::Port & port    
) :
    _port(new Network::Ip::Port(port))
{}

bool Network::Ip::PortConfig::hasPort() const {
  return _port;
}

const Network::Ip::Port & Network::Ip::PortConfig::getPort() const {
  if (!hasPort()) {
    throw std::runtime_error("Must set port before calling this method!");
  }
  return *_port;
}
