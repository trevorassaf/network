#include "system_accept_results_builder.h"

Network::SystemAcceptResultsBuilder::SystemAcceptResultsBuilder() :
    _systemConnectionModule(nullptr),
    _localHost(nullptr),
    _remoteHost(nullptr),
    _hasAddressFamily(false),
    _addressFamily(Network::Ip::AddressFamily::UNSPECIFIED)
{}

Network::SystemAcceptResultsBuilder::~SystemAcceptResultsBuilder() {
  delete _systemConnectionModule;
  delete _localHost;
  delete _remoteHost;
}

Network::SystemAcceptResultsBuilder &
Network::SystemAcceptResultsBuilder::setSystemConnectionModule(
    Network::SystemConnectionModule * system_connection_module    
) {
  if (_systemConnectionModule) {
    throw std::runtime_error("System connection module already set!");
  }
  _systemConnectionModule = system_connection_module;
  return *this;
}

Network::SystemAcceptResultsBuilder &
Network::SystemAcceptResultsBuilder::setLocalHost(
    const Network::Ip::Host & local_host
) {
  delete _localHost;
  _localHost = new Network::Ip::Host(local_host);
  return *this;
}

Network::SystemAcceptResultsBuilder &
Network::SystemAcceptResultsBuilder::setRemoteHost(
    const Network::Ip::Host & remote_host
) {
  delete _remoteHost;
  _remoteHost = new Network::Ip::Host(remote_host);
  return *this;
}

Network::SystemAcceptResultsBuilder &
Network::SystemAcceptResultsBuilder::setAddressFamily(
    Network::Ip::AddressFamily address_family    
) {
  _addressFamily = address_family;
  _hasAddressFamily = true;
  return *this;
}

Network::SystemAcceptResults * Network::SystemAcceptResultsBuilder::build() {
  if (!_systemConnectionModule) {
    throw std::runtime_error("Must set system conneciton module!");
  } 

  if (!_localHost) {
    throw std::runtime_error("Must set local host!");
  }
  
  if (!_remoteHost) {
    throw std::runtime_error("Must set remote host!");
  }

  if (!_hasAddressFamily) {
    throw std::runtime_error("Must set address family!");
  }

  Network::SystemAcceptResults * system_accept_results = new Network::SystemAcceptResults(
      _systemConnectionModule,
      *_localHost,
      *_remoteHost,
      _addressFamily
  );

  _systemConnectionModule = nullptr;

  return system_accept_results;
}
