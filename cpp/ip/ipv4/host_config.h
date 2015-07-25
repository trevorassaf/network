#pragma once

#include "v4_namespace.h"
#include "../port_config.h"
#include "address.h"

class Network::Ip::V4::HostConfig {

  private:
    const Network::Ip::PortConfig _portConfig;

    bool _hasAddress;
    const Network::Ip::V4::Address _address;

  public:
    HostConfig(
        const Network::Ip::PortConfig & portConfig,
        const Network::Ip::V4::Address & address
    );

    bool hasPortConfig() const;
    const Network::Ip::PortConfig & getPortConfig() const;
    bool hasAddress() const;
    const Network::Ip::V4::Address & getAddress() const;
};
