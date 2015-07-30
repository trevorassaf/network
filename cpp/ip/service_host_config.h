#pragma once

#include <ip/ip_namespace>
#include <ip/address_config>
#include <ip/port_config>
#include <ip/address_family>
#include <ip/socket_type>

class Network::Ip::ServiceHostConfig {

  private:
    const Network::Ip::AddressConfig _addressConfig;
    const Network::Ip::PortConfig _portConfig;
    const Network::Ip::AddressFamily _addressFamily;
    const Network::Ip::SocketType _socketType;

  public:
    ServiceHostConfig(
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
