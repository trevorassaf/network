#pragma once

#include "ip_namespace.h"
#include "address_builder.h"
#include "address.h"

class Network::Ip::AddressConfig {

  private:
    bool _hasAddress;
    const Network::Ip::AddressBuilder _addressBuilder;

  public:
    AddressConfig();
    AddressConfig(const Network::Ip::Address & address);

    bool hasAddress() const;
    const Network::Ip::Address getAddress() const;
};
