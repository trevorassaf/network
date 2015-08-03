#pragma once

#include <ip/ip_namespace.h>
#include <ip/address_config.h>
#include <ip/port_config.h>
#include <ip/address_family.h>
#include <ip/socket_type.h>
#include <ip/connecter_host_config.h>

class Network::Ip::ConnecterHostConfigBuilder {

  private:
    Network::Ip::AddressConfig _addressConfig;
    Network::Ip::PortConfig _portConfig;
    Network::Ip::AddressFamily _addressFamily;
    bool _hasSocketType;
    Network::Ip::SocketType _socketType;
     
  public:
    ConnecterHostConfigBuilder();
    ConnecterHostConfigBuilder & setAddressConfig(
        const Network::Ip::AddressConfig & address_config
    );
    ConnecterHostConfigBuilder & setPortConfig(
        const Network::Ip::PortConfig & port_config
    );
    ConnecterHostConfigBuilder & setAddressFamily(
        Network::Ip::AddressFamily address_family
    );
    ConnecterHostConfigBuilder & setSocketType(
        Network::Ip::SocketType socket_type
    );
    const Network::Ip::ConnecterHostConfig build() const;
};
