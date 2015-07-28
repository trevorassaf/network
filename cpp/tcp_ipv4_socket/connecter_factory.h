#pragma once

#include "tcp_ipv4_namespace.h"

class Network::TcpIpv4Socket::ConnecterBuilderFactory {

  public:
    Network::Connecter * getNewInstance();

};
