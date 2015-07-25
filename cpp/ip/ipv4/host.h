#pragma once

#include "v4_namespace.h"
#include "../port.h"
#include "address.h"

class Network::Ip::V4::Host {

  private:
    const Network::Ip::Port * _port;
    const Network::Ip::V4::Address * _address;

  public:
    Host(
        const Network::Ip::Port * port,
        const Network::Ip::V4::Address * address
    );

    const Network::Ip::Port * getPort() const;
    const Network::Ip::V4::Address * getAddress() const;
};
