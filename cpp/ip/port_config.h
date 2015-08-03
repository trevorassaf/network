#pragma once

#include <ip/ip_namespace.h>
#include <ip/port.h>

#include <cstdint>
#include <string>

class Network::Ip::PortConfig {

  private:
    Network::Ip::Port * _port;

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
     * ~PortConfig()
     * - Delete port memory
     */
    ~PortConfig();

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
    const Network::Ip::Port & getPort() const;
};
