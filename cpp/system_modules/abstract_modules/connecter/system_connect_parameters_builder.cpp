#include "system_connect_parameters_builder.h"

Network::SystemConnectParametersBuilder::SystemConnectParametersBuilder() : 
    _remoteHost(nullptr),
    _localHostConfig(nullptr),
    _addressFamily(Network::Ip::AddressFamily::UNSPECIFIED),
    _socketType(Network::Ip::SocketType::STREAM)
{}

Network::SystemConnectParametersBuilder::~SystemConnectParametersBuilder() {
  delete _remoteHost;
  _remoteHost = nullptr;
  delete _localHostConfig;
  _localHostConfig = nullptr;
}

Network::SystemConnectParametersBuilder &
Network::SystemConnectParametersBuilder::setRemoteHost(
    const Network::Ip::Host & remote_host    
) {
  delete _remoteHost;
  _remoteHost = new Network::Ip::Host(remote_host);
  return *this;
}

Network::SystemConnectParametersBuilder &
Network::SystemConnectParametersBuilder::setLocalHostConfig(
    const Network::Ip::ConnecterHostConfig & local_host_config    
) {
  delete _localHostConfig;
  _localHostConfig = new Network::Ip::ConnecterHostConfig(local_host_config);
  return *this;
}
Network::SystemConnectParametersBuilder &
Network::SystemConnectParametersBuilder::setAddressFamily(
    Network::Ip::AddressFamily address_family    
) {
  _addressFamily = address_family;
  return *this;
}

Network::SystemConnectParametersBuilder &
Network::SystemConnectParametersBuilder::setSocketType(
    Network::Ip::SocketType socket_type    
) {
  _socketType = socket_type;
  return *this;
}

Network::SystemConnectParameters
Network::SystemConnectParametersBuilder::build() const {
  return Network::SystemConnectParameters(
     *_remoteHost,
     _localHostConfig,
     _addressFamily,
     _socketType
  ); 
}
