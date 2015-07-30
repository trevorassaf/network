#pragma once

#include <ip/ip_namespace.h>

#include <string>

class Network::Ip::AddressBuilder {

  private:
    bool _hasAddressString;
    std::string _addressString;

  public:
    AddressBuilder();
    AddressBuilder(const Network::Ip::Address & address);
    AddressBuilder & from(const Network::Ip::Address & address);
    AddressBuilder & setAddressString(const std::string & address_string);
    const Network::Ip::Address build() const;
};
