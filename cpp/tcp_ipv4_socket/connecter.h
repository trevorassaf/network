#pragma once

#include "tcp_ipv4_namespace.h"
#include "../system_callers/abstract_callers/caller_modules/system_connecter_module.h"

class Network::TcpIpv4Socket::Connecter {
  
  private:
    Network::SystemConnecterModule * _systemConnecterModule;

  public:
    Connecter(
      Network::SystemConnecterModule * _systemConnecterModule
    );
};
