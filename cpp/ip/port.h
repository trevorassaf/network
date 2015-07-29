#pragma once

#include <ip_namespace>
#include <port_config>

#include <cstdint>
#include <string>

class Network::Ip::Port {

  private:
    /**
     * Port number in host byte-order
     */
    const uint16_t _portNumber;

  public:
    /**
     * Port()
     * @param number : port number in host byte-order
     */
    Port(uint16_t port_number);

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
