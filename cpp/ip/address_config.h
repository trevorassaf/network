#pragma once

#include <ip/ip_namespace.h>
#include <ip/address.h>

class Network::Ip::AddressConfig {

  private:
    Network::Ip::Address * _address;

  public:
    AddressConfig();
    AddressConfig(const Network::Ip::Address & address);
    AddressConfig(const AddressConfig & address_config);
    AddressConfig & operator=(const AddressConfig & address_config);
    ~AddressConfig();

    bool hasAddress() const;
    const Network::Ip::Address & getAddress() const;
};
