#include "service_builder.h"

Network::TcpIpv4Socket::ServiceBuilder::ServiceBuilder(
    Network::SystemServiceBuilderModule * system_service_builder_module    
) :
    _systemServiceBuilderModule(system_service_builder_module)
{}

Network::TcpIpv4Socket::ServiceBuilder *
Network::TcpIpv4Socket::ServiceBuilder::setLocalHostConfig(
    const Network::Ip::V4::LocalHostConfig * ipv4_local_host_config    
) {
  delete _ipv4LocalHostConfig;
  _ipv4LocalHostConfig = new Network::Ip::V4::LocalHostConfig(ipv4_local_host_config);
  return this;
}

Network::TcpIpv4Socket::ServiceBuilder *
Network::TcpIpv4Socket::ServiceBuilder::setBacklogSize(unsigned int backlog_size) {
  _backlogSize = backlog_size;
  return this;
}

const Network::TcpIpv4Socket::Service *
Network::TcpIpv4Socket::ServiceBuilder::build() const {
  Network::SystemOpenAndBindParameters * open_and_bind_parameters =
      new Network::SystemOpenAndBindParameters()
          ->setHostName()
          ->setServiceName();

  const Network::SystemOpenAndBindResults * open_and_bind_results = 
      _systemServiceBuilderModule->openAndBind(open_and_bind_parameters);

  delete open_and_bind_parameters;
  open_and_bind_parameters = nullptr;
  delete open_and_bind_results;
  open_and_bind_results = nullptr;
  
  const Network::SystemListenParameters * listen_parameters =
      new Network::SystemListenParameters()
          ->setBacklogSize(_backlogSize);

  // TODO combine listen and open/bind method call, then combine
  // connect and open/bind call, then combine connect and open call
}
