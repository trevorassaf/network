#pragma once

#include "tcp_ipv4_namespace.h"
#include "../system_callers/abstract_callers/caller_modules/system_connection_module.h"

class Network::TcpIpv4Socket::Connection {
  
  private:
    Network::SystemConnectionModule * _systemConnectionModule;

  public:
    Connection(
      Network::SystemConnectionModule * _systemConnectionModule
    );
};
