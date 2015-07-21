#pragma once

#include "v4_namespace.h"
#include "address.h"
#include "port.h"

class Network::Ip::V4::Host {

  private:
    const Network::Ip::V4::Address _address;
    const Network::Ip::Port _port;

  public:
    Host(
        const Network::Ip::V4::Address & address,
        const Network::Ip::Port & port
    );

    const Network::Ip::V4::Address & getAddress() const;
    const Network::Ip::Port & getPort() const;
};
