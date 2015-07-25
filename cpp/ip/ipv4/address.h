#pragma once

#include "ipv4_namespace.h"

#include <cstdint>
#include <string>

class Network::Ip::V4::Address {

  private:
    const uint32_t _number;

  public:
    /**
     * Address()
     * @param number : ipv4 address number in network byte-order
     */
    Address(uint32_t number);

    /**
     * getNumber()
     * @return ipv4 address number in network byte-order
     */
    uint32_t getNumber() const;

    /**
     * toString()
     * @return dotted decimal ipv4 address string
     */
    const std::string toString() const;
};
