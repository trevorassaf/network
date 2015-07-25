#pragma once

#include "tcp_ipv4_namespace.h"
#include "../ip/ipv4/host.h"
#include "../ip/ipv4/host_config.h"
#include "../system_callers/abstract_callers/caller_modules/system_connecter_module.h"

class Network::TcpIpv4Socket::Connecter {
  
  private:
    Network::SystemConnecterModule * _systemConnecterModule;
    Network::Ip::V4::Host _remoteHost;
    Network::Ip::V4::HostConfig _localHostConfig;

  public:
    Connecter(
        Network::SystemConnecterModule * _systemConnecterModule
    );

    Connecter * setRemoteHost(
        const Network::Ip::V4::Host & remote_host
    );

    Connecter * setLocalHostConfig(
        const Network::Ip::V4::HostConfig & local_host_config
    );

    const TcpIpv4Socket::Connection * connect() const;
};
