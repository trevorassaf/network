#include "connecter_host_config_builder.h"

#include <stdexcept>

Network::Ip::ConnecterHostConfigBuilder::ConnecterHostConfigBuilder() :
    _addressConfig(),
    _portConfig(),
    _addressFamily(Network::Ip::AddressFamily::UNSPECIFIED),
    _hasSocketType(false),
    _socketType(Network::Ip::SocketType::STREAM) // arbitrary default
{}

Network::Ip::ConnecterHostConfigBuilder &
Network::Ip::ConnecterHostConfigBuilder::setAddressConfig(
      const Network::Ip::AddressConfig & address_config
) {
  _addressConfig = address_config;
  return *this;
}

Network::Ip::ConnecterHostConfigBuilder &
Network::Ip::ConnecterHostConfigBuilder::setPortConfig(
    const Network::Ip::PortConfig & port_config
) {
  _portConfig = port_config;
  return *this;
}

Network::Ip::ConnecterHostConfigBuilder &
Network::Ip::ConnecterHostConfigBuilder::setAddressFamily(
    Network::Ip::AddressFamily address_family
) {
  _addressFamily = address_family;
  return *this;
}

Network::Ip::ConnecterHostConfigBuilder &
Network::Ip::ConnecterHostConfigBuilder::setSocketType(
    Network::Ip::SocketType socket_type
) {
  _socketType = socket_type;
  _hasSocketType = true;
  return *this;
}

const Network::Ip::ConnecterHostConfig
Network::Ip::ConnecterHostConfigBuilder::build() const {
  if (!_hasSocketType) {
    throw std::runtime_error("Must specify socket type before building!");
  }
  return Network::Ip::ConnecterHostConfig(
      _addressConfig,
      _portConfig,
      _addressFamily,
      _socketType
  );
}
