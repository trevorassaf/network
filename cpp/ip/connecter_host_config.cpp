#include "connecter_host_config.h"

Network::Ip::ConnecterHostConfig::ConnecterHostConfig(
    const Network::Ip::AddressConfig & address_config,
    const Network::Ip::PortConfig & port_config,
    Network::Ip::AddressFamily address_family,
    Network::Ip::SocketType socket_type
) :
    _addressConfig(address_config),
    _portConfig(port_config),
    _addressFamily(address_family),
    _socketType(socket_type)
{}

const Network::Ip::AddressConfig & Network::Ip::ConnecterHostConfig::getAddressConfig() const {
  return _addressConfig;
}

const Network::Ip::PortConfig & Network::Ip::ConnecterHostConfig::getPortConfig() const {
  return _portConfig;
}

Network::Ip::AddressFamily Network::Ip::ConnecterHostConfig::getAddressFamily() const {
  return _addressFamily;
}

Network::Ip::SocketType Network::Ip::ConnecterHostConfig::getSocketType() const {
  return _socketType;
}
