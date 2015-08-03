#pragma once

#include <ip/ip_namespace.h>
#include <ip/address.h>

class Network::Ip::AddressConfig {

  private:
    Network::Ip::Address * _address;

  public:
    AddressConfig();
    AddressConfig(const Network::Ip::Address & address);
    ~AddressConfig();

    bool hasAddress() const;
    const Network::Ip::Address & getAddress() const;
};
