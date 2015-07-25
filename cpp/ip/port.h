#pragma once

#include "ip_namespace.h"
#include "port_config.h"

#include <cstdint>
#include <string>

class Network::Ip::Port {

  private:
    /**
     * Port number in network byte-order
     */
    const uint16_t _number;

    friend class PortConfig;
    
    Port();

  public:
    /**
     * Port()
     * @param number : port number in network byte-order
     */
    Port(uint16_t number);

    /**
     * getNumber()
     * @return port number in network byte-order
     */
    uint16_t getNumber() const;

    /**
     * toString()
     * @return port string in host byte-order
     */
    const std::string toString() const;
};
