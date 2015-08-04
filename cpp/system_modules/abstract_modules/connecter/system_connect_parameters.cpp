#include "system_connect_parameters.h"

#include <stdexcept>

Network::SystemConnectParameters::SystemConnectParameters(
    const Network::Ip::Host & remote_host,
    const Network::Ip::ConnecterHostConfig * local_host_config,
    Network::Ip::AddressFamily address_family,
    Network::Ip::SocketType socket_type 
) :
    _remoteHost(remote_host),
    _localHostConfig(
        (local_host_config)
            ? new Network::Ip::ConnecterHostConfig(*local_host_config)
            : nullptr
    ),
    _addressFamily(address_family),
    _socketType(socket_type)
{}

Network::SystemConnectParameters::SystemConnectParameters(
    const Network::SystemConnectParameters & parameters
) :
    _remoteHost(parameters._remoteHost),
    _localHostConfig(
        (parameters._localHostConfig)
            ? new Network::Ip::ConnecterHostConfig(*parameters._localHostConfig)
            : nullptr
    ),
    _addressFamily(parameters._addressFamily),
    _socketType(parameters._socketType)
{}

Network::SystemConnectParameters & Network::SystemConnectParameters::operator=(
    const Network::SystemConnectParameters & parameters    
) {
  Network::SystemConnectParameters temp(parameters);
  std::swap(_remoteHost, temp._remoteHost);
  std::swap(_localHostConfig, temp._localHostConfig);
  std::swap(_addressFamily, temp._addressFamily);
  std::swap(_socketType, temp._socketType);
  return *this;
}

Network::SystemConnectParameters::~SystemConnectParameters() {
  delete _localHostConfig;
  _localHostConfig = nullptr;
}

const Network::Ip::Host & Network::SystemConnectParameters::getRemoteHost() const {
  return _remoteHost;
}

bool Network::SystemConnectParameters::hasLocalHostConfig() const {
  return _localHostConfig;
}

const Network::Ip::ConnecterHostConfig & Network::SystemConnectParameters::getLocalHostConfig() const {
  if (!hasLocalHostConfig()) {
    throw std::runtime_error("System connect parametes instance does not have local host config!");
  }
  return *_localHostConfig;
}

Network::Ip::AddressFamily Network::SystemConnectParameters::getAddressFamily() const {
  return _addressFamily;
}

Network::Ip::SocketType Network::SystemConnectParameters::getSocketType() const {
  return _socketType;
}
