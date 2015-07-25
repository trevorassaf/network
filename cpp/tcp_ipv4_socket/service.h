#pragma once

#include "tcp_ipv4_namespace.h"
#include "../ip/ipv4/host_config.h"
#include "../system_callers/abstract_callers/caller_modules/system_service_module.h"

class Network::TcpIpv4Socket::Service {
  
  private:
    Network::SystemServiceModule * _systemServiceModule;
    const Network::Ip::V4::HostConfig * _ipv4HostConfig;
    bool _isListening;

  public:
    Service(
        Network::SystemServiceModule * _systemServiceModule
    );

    Service * setHostConfig(
        const Network::Ip::V4::HostConfig * host_config   
    );

    Service * listen();

    Network::TcpIpv4Socket::Connection * accept() const;
};
