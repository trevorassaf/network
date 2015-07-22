#pragma once

#include "v6_namespace.h"
#include "../port.h"
#include "../host.h"
#include "../address.h"
#include "address.h"

class Network::Ip::V6::Host : public Network::Ip::Host {

  private:
    const Network::Ip::V6::Address _address;
    const Network::Ip::Port _port;
  
  public:
    Host(
        const Network::Ip::V6::Address & address,
        const Network::Ip::Port & port
    );
    const Network::Ip::Port & getPort() const override;
    const Network::Ip::V6::Address & getAddress() const override;
};
