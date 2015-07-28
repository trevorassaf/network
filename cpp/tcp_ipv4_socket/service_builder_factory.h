#pragma once

#include "tcp_ipv4_namespace.h"

class Network::TcpIpv4Socket::ServiceBuilderFactory {

  public:
    Network::ServiceBuilder * getNewInstance();

};
