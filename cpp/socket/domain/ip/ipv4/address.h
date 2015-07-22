#pragma once

#include "v4_namespace.h"
#include "../address.h"

#include <string>
#include <cstdint>

class Network::Ip::V4::Address : public Network::Ip::Address {

  private:
    const uint32_t _ipv4;

    Address(uint32_t ipv4_number);

  public:
    uint32_t getNumber() const;
    const std::string getAddressString() const override;
};
