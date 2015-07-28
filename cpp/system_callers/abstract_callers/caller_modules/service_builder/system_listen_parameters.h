#pragma once

#include "network_namespace.h"

class Network::SystemListenParameters {

  private:
    const Network::Ip::ServiceHostConfig _serviceHostConfig;

  public:
    SystemListenParameters(
        const Network::Ip::ServiceHostConfig & service_host_config 
    );

    const Network::Ip::ServiceHostConfig & getServiceHostConfig() const;
};
