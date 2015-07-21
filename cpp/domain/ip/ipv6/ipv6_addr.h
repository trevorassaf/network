#pragma once

#include "../../../network.h"
#include "../ip_addr.h"

#include <string>
#include <cstdint>

#define IPV6_NUM_BYTES 0x10

class Network::Ip::Ipv6Address : Network::Ip::IpAddress {

  private:
    const uint8_t _ipv6[IPV6_NUM_BYTES];

    Ipv6Address(const uint8_t ipv6_buffer);

  public:
    const uint8_t * getNumber() const;
    const std::string getAddressString() const override;
};
