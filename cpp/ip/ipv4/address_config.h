#pragma once

#include "v4_namespace.h"
#include "address.h"

#include <cstdint>
#include <string>

class Network::Ip::V4::AddressConfig {

  private:
    const bool _hasAddress;
    const Network::Ip::V4::Address _address;

  public:
    /**
     * AddressConfig()
     * @param number : ipv4 address number in network byte-order
     */
    AddressConfig();
    
    /**
     * AddressConfig()
     * @param number : ipv4 address
     */
    AddressConfig(const Network::Ip::V4::Address & address);

    /**
     * hasAddress()
     * @return true iff ipv4 address is set
     */
    bool hasAddress() const;

    /**
     * getAddress()
     * @return address
     * @throw NetworkRuntimeError if no address exists
     */
    const Network::Ip::V4::Address & getAddress() const;
};
