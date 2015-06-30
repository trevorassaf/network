#include "../headers/host.h"

/**
 * Network::HostBuilder
 */
Network::HostBuilder::HostBuilder() :
    _isPortSpecified(false),
    _isAddressSet(false)
{}

Network::HostBuilder * Network::HostBuilder::setIpv4(const Network::Ipv4 * ipv4) {
  _isIpv4 = true;
  _isAddressSet = true;
  _ipv4 = ipv4;
  return this;
}

Network::HostBuilder * Network::HostBuilder::setIpv6(const Network::Ipv6 * ipv6) {
  _isIpv4 = false;
  _isAddressSet = true;
  _ipv6 = ipv6;
  return this;
}

Network::HostBuilder * Network::HostBuilder::setPort(const Network::Port * port) {
  _isPortSpecified = true;
  _port = port;
  return this;
}

const Network::Host Network::HostBuilder::build() {
  if (!_isAddressSet) {
    throw std::runtime_error("Can't build Network::Host without ip address!");
  }

  return new Network::Host(_isIpv4, _isPortSpecified, _ipv4, _ipv6, _port);
}

/**
 * Network::Host
 */
Network::Host::Host(
    bool is_ipv4,
    bool is_port_specified,
    const Network::Ipv4 * ipv4,
    const Network::Ipv6 * ipv6,
    const Network::Port * port
) :
  _isIpv4(is_ipv4),
  _isPortSpecified(is_port_specified),
{
  _ipv4 = (ipv4) ? new Network::Ipv4(*ipv4) : nullptr;
  _ipv6 = (ipv6) ? new Network::Ipv6(*ipv6) : nullptr;
  _port = (port) ? new Network::Port(*port) : nullptr;

  if (is_ipv4) {
    _ipv6 = Network::Ipv6::fromIpv4(_ipv4); 
  }
}

Network::Host::~Host() {
  delete _ipv4;
  _ipv4 = nullptr;
  delete _ipv6;
  _ipv6 = nullptr;
  delete _port;
  _port = nullptr;
}

bool Network::Host::isIpv4() const {
  return _isIpv4;
}

bool Network::Host::isPortSpecified() const {
  return _isPortSpecified;
}

const Network::Ipv4 * Network::Host::getIpv4() const {
  if (!_isIpv4) {
    throw std::runtime_error("Host using ipv6 not ipv4! Check isIpv4()");
  }

  return _ipv4;
}

const Network::Ipv6 * Network::Host::getIpv6() const {
  return _ipv6;
}

const Network::Port * Network::Host::getPort() const {
  if (!_isPortSpecified) {
    throw std::runtime_error("Port is unspecified! Check with isPortSpecified()");
  }

  return _port;
}
