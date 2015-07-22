#pragma once

#include "v6_namespace.h"

#include "../../../socket_config.h"

class Network::Ip::V6::SocketConfig : Network::SocketConfig {
  public:
    virtual Network::Ip::V6::SocketConfig * setIsIpv6Only(bool is_ipv6_only) = 0;
    virtual Network::Ip::V6::SocketConfig * enableIpv6Only() = 0;
    virtual Network::Ip::V6::SocketConfig * disableIpv6Only() = 0;
};
