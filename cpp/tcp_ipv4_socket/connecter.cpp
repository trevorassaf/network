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
  // Open socket
  const Network::SystemOpenParameters * open_params = new Network::SystemOpenParameters();
  const Network::SystemOpenResults * open_results = _systemConnecterModule->open(open_params);
  delete open_results;

  // Bind to local address, if set
  // Connect
}
