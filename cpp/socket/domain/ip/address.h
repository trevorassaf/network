#pragma once

#include "ip_namespace.h"

#include <string>

class Network::Ip::Address {
  public:
    virtual const std::string getAddressString() const = 0;
};
