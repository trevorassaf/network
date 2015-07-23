#pragma once

#include "network_namespace.h"

class Network::SystemOpenParameters {

  private:
    int _type;
    int _domain;
    int _protocol;

  public:
    SystemOpenParameters(
        int type,
        int domain,
        int protocol
    );

    int getType() const;
    int getDomain() const;
    int getProtocol() const;
};
