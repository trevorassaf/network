#include "port_config.h"

#include <stdexcept>

Network::Ip::PortConfig::PortConfig() : _port(nullptr) {}

Network::Ip::PortConfig::PortConfig(
    const Network::Ip::Port & port    
) :
    _port(new Network::Ip::Port(port))
{}

Network::Ip::PortConfig::PortConfig(
    const Network::Ip::PortConfig & port_config    
) :
    _port(
        (port_config._port)
            ? new Network::Ip::Port(port_config.getPort())
            : nullptr
    )
{}

Network::Ip::PortConfig & Network::Ip::PortConfig::operator=(
    const Network::Ip::PortConfig & port_config    
) {
  delete _port;
  _port = (port_config.hasPort())
      ? new Network::Ip::Port(port_config.getPort())
      : nullptr;
  return *this;
}

Network::Ip::PortConfig::~PortConfig() {
  delete _port;
  _port = nullptr;
}

bool Network::Ip::PortConfig::hasPort() const {
  return _port;
}

const Network::Ip::Port & Network::Ip::PortConfig::getPort() const {
  if (!hasPort()) {
    throw std::runtime_error("Must set port before calling this method!");
  }
  return *_port;
}
