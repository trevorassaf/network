#include "service_host_config.h"

Network::Ip::ServiceHostConfig::ServiceHostConfig(
    const Network::Ip::AddressConfig & address_config,
    const Network::Ip::PortConfig & port_config,
    Network::Ip::AddressFamily address_family,
    Network::Ip::SocketType socket_type,
    unsigned int backlog_size
) :
    _addressConfig(address_config),
    _portConfig(port_config),
    _addressFamily(address_family),
    _socketType(socket_type),
    _backlogSize(backlog_size)
{}

const Network::Ip::AddressConfig & Network::Ip::ServiceHostConfig::getAddressConfig() const {
  return _addressConfig;
}

const Network::Ip::PortConfig & Network::Ip::ServiceHostConfig::getPortConfig() const {
  return _portConfig;
}

Network::Ip::AddressFamily Network::Ip::ServiceHostConfig::getAddressFamily() const {
  return _addressFamily;
}

Network::Ip::SocketType Network::Ip::ServiceHostConfig::getSocketType() const {
  return _socketType;
}

unsigned int Network::Ip::ServiceHostConfig::getBacklogSize() const {
  return _backlogSize;
}
