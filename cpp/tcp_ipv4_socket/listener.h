#pragma once

#include "tcp_ipv4_namespace.h"
#include "../ip/ipv4/host_config.h"
#include "../system_callers/abstract_callers/caller_modules/system_listener_module.h"

class Network::TcpIpv4Socket::Listener {
  
  private:
    Network::SystemListenerModule * _systemListenerModule;
    Network::Ip::V4::HostConfig _ipv4HostConfig;

  public:
    Listener(
      Network::SystemListenerModule * _systemListenerModule
    );

    Listener * setLocalHostConfig(
        const Network::Ip::V4::HostConfig & ipv4_host_config
    );

    Network::TcpIpv4Socket::Service
};
