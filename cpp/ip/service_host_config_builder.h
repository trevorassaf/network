#pragma once

#include <ip/ip_namespace.h>
#include <ip/address_config.h>
#include <ip/port_config.h>
#include <ip/address_family.h>
#include <ip/socket_type.h>
#include <ip/service_host_config.h>

class Network::Ip::ServiceHostConfigBuilder {

  private:
    static unsigned int DEFAULT_BACKLOG_SIZE;

    Network::Ip::AddressConfig _addressConfig;
    Network::Ip::PortConfig _portConfig;
    Network::Ip::AddressFamily _addressFamily;
    bool _hasSocketType;
    Network::Ip::SocketType _socketType;
    unsigned int _backlogSize;
     
  public:
    ServiceHostConfigBuilder();
    ServiceHostConfigBuilder & setAddressConfig(const Network::Ip::AddressConfig & address_config);
    ServiceHostConfigBuilder & setPortConfig(const Network::Ip::PortConfig & port_config);
    ServiceHostConfigBuilder & setAddressFamily(Network::Ip::AddressFamily address_family);
    ServiceHostConfigBuilder & setSocketType(Network::Ip::SocketType socket_type);
    ServiceHostConfigBuilder & setBacklogSize(unsigned int backlog_size);
    const Network::Ip::ServiceHostConfig build() const;
};
