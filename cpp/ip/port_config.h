#pragma once

#include "ip_namespace.h"
#include "port.h"

#include <cstdint>
#include <string>

class Network::Ip::PortConfig {

  private:
    const Network::Ip::Port _port;
    bool _hasPort;

  public:
    /**
     * PortConfig()
     * @param number : port number in network byte-order
     */
    PortConfig();

    PortConfig(const Network::Ip::Port & port);

    /**
     * hasPort()
     * @return true iff port number is specified
     */
    bool hasPort() const;

    /**
     * getPort()
     * @return port
     * @throw NetworkRuntimeException iff port is not set
     */
    const Network::Ip::Port & getPort() const;
};
