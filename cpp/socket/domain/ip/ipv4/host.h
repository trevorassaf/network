#pragma once

#include "v4_namespace.h"
#include "../port.h"
#include "../host.h"
#include "../address.h"
#include "address.h"

class Network::Ip::V4::Host : public Network::Ip::Host {

  private:
    const Network::Ip::V4::Address _address;
    const Network::Ip::Port _port;
  
  public:
    Host(
        const Network::Ip::V4::Address & address,
        const Network::Ip::Port & port
    );
    const Network::Ip::Port & getPort() const override;
    const Network::Ip::V4::Address & getAddress() const override;
};
