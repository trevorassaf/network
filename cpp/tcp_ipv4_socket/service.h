#pragma once

#include "tcp_ipv4_namespace.h"
#include "../ip/ipv4/local_host_config.h"
#include "../system_callers/abstract_callers/caller_modules/system_service_module.h"

class Network::TcpIpv4Socket::Service {
  
  private:
    Network::SystemServiceModule * _systemServiceModule;
    const Network::Ip::V4::LocalHostConfig * _ipv4LocalHostConfig;

  public:
    Service(
        Network::SystemServiceModule * _systemServiceModule,
        const Network::Ip::V4::LocalHostConfig * _ipv4LocalHostConfig
    );
    
    ~Service();

    const Network::Ip::V4::LocalHostConfig * getLocalHostConfig() const;

    Network::TcpIpv4Socket::Connection * accept() const;
};
