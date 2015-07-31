#pragma once

#include <ip/ip_namespace.h>
#include <ip/port_builder.h>
#include <ip/port.h>

#include <cstdint>
#include <string>

class Network::Ip::PortConfig {

  private:
    bool _hasPort;
    Network::Ip::PortBuilder _portBuilder;

  public:
    /**
     * PortConfig()
     * - Portless state
     */
    PortConfig();

    /**
     * PortConfig()
     * - Portful state
     */
    PortConfig(const Network::Ip::Port & port);

    /**
     * hasPort()
     * @return true iff in portful state
     */
    bool hasPort() const;

    /**
     * getPort()
     * @return port
     * @throw runtime_error iff not in portful state 
     */
    const Network::Ip::Port getPort() const;
};
