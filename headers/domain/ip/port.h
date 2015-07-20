#pragma once

#include "../../network.h"

#include <cstdint>
#include <string>

class Network::Port {

  private:
    /**
     * Port number in network-byte order.
     */
    const uint16_t _port;

    friend class Network::PortBuilder;
    Port(uint16_t port);

  public:
    uint16_t getNumber() const;
    const std::string toString() const;
};
