#pragma once

#include "v4_namespace.h"
#include "port.h"

#include <string>

class Network::Ip::IpAddress {
  public:
    virtual const std::string getAddressString() const = 0;
    virtual const uint8_t * getBuffer() const = 0;
    virtual const Network::Ip::Port & getPort() const = 0;
};
