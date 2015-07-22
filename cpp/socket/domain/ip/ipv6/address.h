#pragma once

#include "v6_namespace.h"
#include "../address.h"

#include <string>
#include <cstdint>

#define IPV6_NUM_BYTES 0x10

class Network::Ip::V6::Address : public Network::Ip::Address {

  private:
    const uint8_t _ipv6[IPV6_NUM_BYTES];

    Address(const uint8_t * ipv6_buffer);

  public:
    const uint8_t * getNumber() const;
    const std::string getAddressString() const override;
};
