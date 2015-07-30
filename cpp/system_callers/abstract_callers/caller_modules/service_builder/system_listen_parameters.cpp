#include "system_listen_parameters.h"

Network::SystemListenParameters::SystemListenParameters(
    const Network::Ip::ServiceHostConfig & service_host_config    
) :
    _serviceHostConfig(service_host_config)
{}

const Network::Ip::ServiceHostConfig &
Network::SystemListenParameters::getServiceHostConfig() const {
  return _serviceHostConfig;   
}
