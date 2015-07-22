#pragma once

#include "ip_namespace.h" 

#include <cstdint>
#include <string>

class Network::Ip::Port {

  private:
    /**
     * Port number in network-byte order.
     */
    const uint16_t _port;

    friend class Network::Ip::PortBuilder;
    Port(uint16_t port);

  public:
    uint16_t getNumber() const;
    const std::string toString() const;
};
