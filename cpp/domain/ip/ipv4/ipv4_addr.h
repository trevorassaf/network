#pragma once

#include "../../../network.h"
#include "../ip_addr.h"

#include <string>
#include <cstdint>

class Network::Ip::Ipv4Address : Network::Ip::IpAddress {

  private:
    const uint32_t _ipv4;

    Ipv4Address(uint32_t ipv4_number);

  public:
    uint32_t getNumber() const;
    const std::string getAddressString() const override;
};
