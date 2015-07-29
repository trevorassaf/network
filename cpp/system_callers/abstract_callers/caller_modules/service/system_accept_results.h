#pragma once

#include "../connection/system_connection_module.h"
#include <ip/host>

class Network::SystemAcceptResults {

  private:
    const Network::SystemConnectionModule * _systemConnectionModule;
    const Network::Ip::Host _localHost;
    const Network::Ip::Host _remoteHost;

  public:
    SystemAcceptResults(
        const Network::SystemConnectionModule * system_connection_module,
        const Network::Ip::Host & local_host,
        const Network::Ip::Host & remote_host
    );

    const Network::SystemConnectionModule * moveSystemConnectionModule() const;
    const Network::Ip::Host & getLocalHost() const;
    const Network::Ip::Host & getRemoteHost() const;
};
