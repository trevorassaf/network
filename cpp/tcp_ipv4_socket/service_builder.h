#pragma once

#include "tcp_ipv4_namespace.h"
#include "../ip/ipv4/local_host_config.h"
#include "../system_callers/abstract_callers/caller_modules/system_service_builder_module.h"

class Network::TcpIpv4Socket::ServiceBuilder {

  private:
    Network::SystemServiceBuilderModule * _systemServiceBuilderModule;
    const Network::Ip::V4::LocalHostConfig * _ipv4LocalHostConfig;
    unsigned int _backlogSize;

  public:
    ServiceBuilder(
        Network::SystemServiceBuilderModule * system_service_builder_module,
    );

    Network::TcpIpv4Socket::ServiceBuilder * setLocalHostConfig(
        const Network::Ip::V4::LocalHostConfig * ipv4_local_host_config    
    );

    Network::TcpIpv4Socket::ServiceBuilder * setBacklogSize(
        unsigned int backlog_size
    );

    const Network::TcpIpv4Socket::Service * build() const;
};
