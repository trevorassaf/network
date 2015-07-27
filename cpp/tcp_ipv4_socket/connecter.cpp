#include "connecter.h"

Network::TcpIpv4Socket::Connecter::Connecter(
    Network::SystemConnecterModule * system_connecter_module    
) :
    _systemConnecterModule(system_connecter_module)
{}

Network::TcpIpv4Socket::Connecter * Network::TcpIpv4Socket::Connecter::setRemoteHost(
    const Network::Ip::V4::Host * remote_host
) {
  _remoteHost = remote_host;
  return this;
}

Network::TcpIpv4Socket::Connecter * Network::TcpIpv4Socket::Connecter::setLocalHostConfig(
    const Network::Ip::V4::Host * local_host_config 
) {
  _localHostConfig = local_host_config;
  return this;
}

const Network::TcpIpv4Socket::Connection * Network::TcpIpv4Socket::connect() const {
  if (_localHostConfig) {
    // Open and bind socket
    const Network::SystemOpenAndBindParameters open_and_bind_params(
        Network::SocketType::IPV4,
        Network::SocketDomain::STREAM,
        _localHostConfig
    );
    const Network::SystemOpenAndBindResults * results =
        _systemConnecterModule->openAndBind(&open_and_bind_params);
    delete results;
  } else {
    // Open socket
    const Network::SystemOpenParameters open_params(
        Network::SocketType::IPV4,
        Network::SocketDomain::STREAM
    );
    const Network::SystemOpenResults * results =
        _systemConnecterModule->open(&open_params);
    delete results;
  }

  // Connect
  const Network::SystemConnectParameters connect_params(_remoteHost);
  const Network::SystemConnectResults * connect_results = 
    _systemConnecterModule->connect(connect_params);
  
  const Network::TcpIpv4Socket::Connection * connection =
      new Network::TcpIpv4Socket::Connection(connect_params);
  delete connect_results;

  return connection;
}
