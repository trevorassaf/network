#pragma once

#include "v4_namespace.h"
#include "host.h"

class Network::Ip::V4::HostBuilder {

  private:
    bool _hasAddress;
    Network::Ip::V4::Address _address;
    bool _hasPort;
    Network::Ip::Port _port;

  public:
    Network::Ip::V4::HostBuilder & setAddress(
        const Network::Ip::V4::Address & address
    );

    Network::Ip::V4::HostBuilder & setPort(
        const Network::Ip::Port & port    
    );

    const Network::Ip::V4::Host build() const;
    const Network::Ip::V4::Host * buildNew() const;
};
