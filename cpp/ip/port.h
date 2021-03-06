#pragma once

#include <ip/ip_namespace.h>
#include <ip/port_config.h>

#include <cstdint>
#include <string>

class Network::Ip::Port {

  private:
    /**
     * Port number in host byte-order
     */
    uint16_t _portNumber;

  public:
    /**
     * Port()
     * @param number : port number in host byte-order
     */
    Port(uint16_t port_number);

    Port(const Port & port);

    Port & operator=(const Port & port);

    /**
     * getNumber()
     * @return port number in host byte-order
     */
    uint16_t getPortNumber() const;

    /**
     * toString()
     * @return port string in host byte-order
     */
    const std::string toString() const;
};
