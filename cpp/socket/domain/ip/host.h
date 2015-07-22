#pragma once

#include "ip_namespace.h"
#include "port.h"
#include "address.h"

class Network::Ip::Host {
  public:
    virtual const Network::Ip::Address & getAddress() const = 0;
    virtual const Network::Ip::Port & getPort() const = 0;
};
