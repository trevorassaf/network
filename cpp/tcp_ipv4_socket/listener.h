#pragma once

#include "tcp_ipv4_namespace.h"
#include "../system_callers/abstract_callers/caller_modules/system_listener_module.h"

class Network::TcpIpv4Socket::Listener {
  
  private:
    Network::SystemListenerModule * _systemListenerModule;

  public:
    Listener(
      Network::SystemListenerModule * _systemListenerModule
    );
};
