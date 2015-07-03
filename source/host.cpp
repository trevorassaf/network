#include "../headers/host.h"

#include <stdexcept>

Network::Host::Host() : _isIpv4(true), _hasPort(false) {}

Network::Host::Host(const Network::Ipv4 & ipv4) : 
    _isIpv4(true),
    _hasPort(false),
    _ipv4(ipv4)
{}

Network::Host::Host(const Network::Ipv6 & ipv6) : 
    _isIpv4(false),
    _hasPort(false),
    _ipv6(ipv6)
{}

Network::Host::Host(const Network::Ipv4 & ipv4, const Network::Port & port) : 
    _isIpv4(true),
    _hasPort(true),
    _ipv4(ipv4),
    _port(port)
{}

Network::Host::Host(const Network::Ipv6 & ipv6, const Network::Port & port) : 
    _isIpv4(false),
    _hasPort(false),
    _ipv6(ipv6),
    _port(port)
{}

bool Network::Host::isIpv4() const {
  return _isIpv4;
}

bool Network::Host::hasPort() const {
  return _hasPort;
}

const Network::Ipv4 & Network::Host::getIpv4() const {
  if (!_isIpv4) {
    throw std::runtime_error("Host using ipv6 not ipv4! Check isIpv4()");
  }

  return _ipv4;
}

const Network::Ipv6 & Network::Host::getIpv6() const {
  return _ipv6;
}

const Network::Port & Network::Host::getPort() const {
  if (!_hasPort) {
    throw std::runtime_error("Port is unspecified! Check with hasPort()");
  }

  return _port;
}

bool Network::Host::operator==(const Network::Host & host) {
  if (_isIpv4) {
    return _ipv6 == host._ipv6 && (!_hasPort  || _port == host._port);
  } else {
    return _ipv4 == host._ipv4 && (!_hasPort  || _port == host._port);
  }
}

bool Network::Host::operator!=(const Network::Host & host) {
  return !(*this == host);
}
