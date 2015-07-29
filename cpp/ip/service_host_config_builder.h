#pragma once

#include <ip_namespace>
#include <address_config_builder>
#include <port_config_builder>
#include <service_host_config>

class Network::Ip::ServiceHostConfigBuilder {

  private:
    Network::Ip::AddressConfig _addressConfig;
    Network::Ip::PortConfig _portConfig;
    Network::Ip::AddressFamily _addressFamily;
    bool _hasSocketType;
    Network::Ip::SocketType _socketType;
     
  public:
    ServiceHostConfigBuilder();
    ServiceHostConfigBuilder & setAddressConfig(Network::Ip::AddressConfig & address_config);
    ServiceHostConfigBuilder & setPortConfig(Network::Ip::PortConfig & port_config);
    ServiceHostConfigBuilder & setAddressFamily(Network::Ip::AddressFamily address_family);
    ServiceHostConfigBuilder & setSocketType(Network::Ip::SocketType socket_type);
    const Network::Ip::ServiceHostConfig build() const;
};
