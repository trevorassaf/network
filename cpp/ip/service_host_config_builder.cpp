#include "service_host_config_builder.h"

#include <stdexcept>

unsigned int Network::Ip::ServiceHostConfigBuilder::DEFAULT_BACKLOG_SIZE = 10;

Network::Ip::ServiceHostConfigBuilder::ServiceHostConfigBuilder() :
    _addressConfig(),
    _portConfig(),
    _addressFamily(Network::Ip::AddressFamily::UNSPECIFIED),
    _hasSocketType(false),
    _socketType(Network::Ip::SocketType::STREAM), // arbitrary default
    _backlogSize(DEFAULT_BACKLOG_SIZE)
{}

Network::Ip::ServiceHostConfigBuilder &
Network::Ip::ServiceHostConfigBuilder::setAddressConfig(
      const Network::Ip::AddressConfig & address_config
) {
  _addressConfig = address_config;
  return *this;
}

Network::Ip::ServiceHostConfigBuilder &
Network::Ip::ServiceHostConfigBuilder::setPortConfig(
    const Network::Ip::PortConfig & port_config
) {
  _portConfig = port_config;
  return *this;
}

Network::Ip::ServiceHostConfigBuilder &
Network::Ip::ServiceHostConfigBuilder::setAddressFamily(
    Network::Ip::AddressFamily address_family
) {
  _addressFamily = address_family;
  return *this;
}

Network::Ip::ServiceHostConfigBuilder &
Network::Ip::ServiceHostConfigBuilder::setSocketType(
    Network::Ip::SocketType socket_type
) {
  _socketType = socket_type;
  _hasSocketType = true;
  return *this;
}

Network::Ip::ServiceHostConfigBuilder &
Network::Ip::ServiceHostConfigBuilder::setBacklogSize(
    unsigned int backlog_size
) {
  _backlogSize = backlog_size;
  return *this;
}

const Network::Ip::ServiceHostConfig
Network::Ip::ServiceHostConfigBuilder::build() const {
  if (!_hasSocketType) {
    throw std::runtime_error("Must specify socket type before building!");
  }
  return Network::Ip::ServiceHostConfig(
      _addressConfig,
      _portConfig,
      _addressFamily,
      _socketType,
      _backlogSize
  );
}
