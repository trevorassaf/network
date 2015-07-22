#pragma once

#include "v6_namespace.h"
#include "socket_config.h"
#include "socket.h"
#include "../../../socket_builder.h"

class Network::Ip::V6::SocketBuilder :
      public Network::SocketBuilder, 
      public Network::Ip::V6::SocketConfig {

  private:
    bool _isIpv6OnlySet, _isIpv6Only;

  public:
    Network::Ip::V6::SocketBuilder * setIsIpv6Only(bool is_ipv6_only) override;
    Network::Ip::V6::SocketBuilder * enableIpv6Only() override;
    Network::Ip::V6::SocketBuilder * disableIpv6Only() override;
    
    virtual Network::Ip::V6::Socket * build() const override;
};
