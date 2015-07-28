#include "host.h"

Network::Ip::Host::Host(
    const Network::Ip::Address & address,
    const Network::Ip::Port & port
) :
    _address(address),
    _port(port)
{}

const Network::Ip::Address & Network::Ip::Host::getAddress() const {
  return _address;
}

const Network::Ip::Port & Network::Ip::Host::getPort() const {
  return _port;
}
