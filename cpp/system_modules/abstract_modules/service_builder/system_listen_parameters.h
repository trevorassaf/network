#pragma once

#include <ip/service_host_config>

namespace Network {
  
    class SystemListenParameters {

    private:
      const Network::Ip::ServiceHostConfig _serviceHostConfig;

    public:
      SystemListenParameters(
          const Network::Ip::ServiceHostConfig & service_host_config 
      );

      const Network::Ip::ServiceHostConfig & getServiceHostConfig() const;
  };
};
