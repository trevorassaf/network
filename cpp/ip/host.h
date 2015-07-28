#pragma once

#include "ip_namespace.h"
#include "address.h"
#include "port.h"

class Network::Ip::Host {
  
  private:
    const Network::Ip::Address _address; 
    const Network::Ip::Port _port;

  public:
    Host(
        const Network::Ip::Address & address,
        const Network::Ip::Port & port
    );
    const Network::Ip::Address & getAddress() const;
    const Network::Ip::Port & getPort() const;
};
