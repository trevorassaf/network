#include "port_config.h"

Network::Ip::PortConfig::PortConfig() : _hasPort(false) {}

Network::Ip::PortConfig::PortConfig(
    const Network::Ip::Port & port    
) :
    _hasPort(true),
    _portBuilder(port)    
{}

bool Network::Ip::PortConfig::hasPort() const {
  return _hasPort;
}

const Network::Ip::Port Network::Ip::PortConfig::getPort() const {
  if (!_hasPort) {
    throw std::runtime_error("Must set port before calling this method!");
  }
  return _portBuilder.build();
}
