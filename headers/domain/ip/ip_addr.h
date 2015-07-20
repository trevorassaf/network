#pragma once

#include "../../network.h"

#include <string>

class Network::Ip::IpAddress {
  public:
    virtual const std::string getAddressString() const = 0;
};
