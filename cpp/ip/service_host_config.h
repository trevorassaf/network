#pragma once

#include <ip_namespace>
#include <address_config>
#include <port_config>

enum class Network::Ip::AddressFamily {
  V4,
  V6,
  UNSPECIFIED 
};

enum class Network::Ip::SocketType {
  STREAM,
  DATAGRAM
};

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
