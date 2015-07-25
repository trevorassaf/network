#pragma once

#include "tcp_ipv4_namespace.h"
#include "../system_callers/abstract_callers/caller_modules/system_service_module.h"

class Network::TcpIpv4Socket::Service {
  
  private:
    Network::SystemServiceModule * _systemServiceModule;

  public:
    Service(
      Network::SystemServiceModule * _systemServiceModule
    );
};
