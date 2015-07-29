#pragma once

#include <ip_namespace>
#include <address_builder>
#include <address>

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
