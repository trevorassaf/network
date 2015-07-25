#pragma once

#include "network_namespace.h"
#include "../../../../socket_type.h"
#include "../../../../socket_domain.h"

class Network::SystemOpenParameters {

  private:
    Network::SocketType _type;
    Network::SocketDomain _domain;

  public:
    SystemOpenParameters(
        Network::SocketType type,
        Network::SocketDomain domain
    );

    Network::SocketType getType() const;
    Network::SocketDomain getDomain() const;
};
