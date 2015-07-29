#pragma once

#include <ip/ip_namespace>

#include <string>

class Network::Ip::Address {
 
  private:
    const std::string _addressString;

    friend class Network::Ip::AddressConfig;
    Address();

  public:
    Address(const std::string & address_string);
    const std::string & getAddressString() const;
};
