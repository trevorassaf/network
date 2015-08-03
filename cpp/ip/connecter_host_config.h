#pragma once

#include <ip/ip_namespace.h>
#include <ip/address_config.h>
#include <ip/port_config.h>
#include <ip/address_family.h>
#include <ip/socket_type.h>

class Network::Ip::ConnecterHostConfig {

  private:
    const Network::Ip::AddressConfig _addressConfig;
    const Network::Ip::PortConfig _portConfig;
    const Network::Ip::AddressFamily _addressFamily;
    const Network::Ip::SocketType _socketType;

  public:
    ConnecterHostConfig(
        const Network::Ip::AddressConfig & address_config,
        const Network::Ip::PortConfig & port_config,
        const Network::Ip::AddressFamily address_family,
        const Network::Ip::SocketType socket_type
    );

    const Network::Ip::AddressConfig & getAddressConfig() const;
    const Network::Ip::PortConfig & getPortConfig() const;
    Network::Ip::AddressFamily getAddressFamily() const;
    Network::Ip::SocketType getSocketType() const; 
};
