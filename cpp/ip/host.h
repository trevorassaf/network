#pragma once

#include <ip/ip_namespace.h>
#include <ip/address.h>
#include <ip/port.h>

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
