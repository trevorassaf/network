#include "../headers/server_config.h"

#include <cassert>
#include <netinet/in.h>
#include <sys/socket.h>
#include <stdexcept>
#include <cstring>

/**
 * Server Configutation.
 */
const Network::ServerConfig::IpAddressFamilyMap Network::ServerConfig::IP_ADDRESS_FAMILY_MAP = {
  {Network::ServerConfig::IpVersion::IPV4, AF_INET},
  {Network::ServerConfig::IpVersion::IPV6, AF_INET6},
  {Network::ServerConfig::IpVersion::UNSPECIFIED, AF_UNSPEC}
};

const Network::ServerConfig::ReverseIpAddressFamilyMap Network::ServerConfig::REVERSE_IP_ADDRESS_FAMILY_MAP = {
  {AF_INET, Network::ServerConfig::IpVersion::IPV4},
  {AF_INET6, Network::ServerConfig::IpVersion::IPV6},
  {AF_UNSPEC, Network::ServerConfig::IpVersion::UNSPECIFIED}
};

Network::ServerConfig::ServerConfig(
    IpVersion ip_version,
    AddressType address_type,
    const std::string & domain,
    const Network::Ipv4 & ipv4,
    const Network::Ipv6 & ipv6,
    const Network::Port & port
) :
    _ipVersion(ip_version),
    _addressType(address_type),
    _domain(domain),
    _ipv4(ipv4),
    _ipv6(ipv6),
    _port(port)
{}

Network::ServerConfig::ServerConfig(
    const Network::ServerConfig & server_config
) : 
    _ipVersion(server_config._ipVersion),
    _addressType(server_config._addressType),
    _domain(server_config._domain),
    _ipv4(server_config._ipv4),
    _ipv6(server_config._ipv6),
    _port(server_config._port)
{}

Network::ServerConfig::IpVersion Network::ServerConfig::getIpVersion() const {
  return _ipVersion; 
}

Network::ServerConfig::AddressType Network::ServerConfig::getAddressType() const {
  return _addressType;
}

int Network::ServerConfig::getIpAddressFamily() const {
  return Network::ServerConfig::IP_ADDRESS_FAMILY_MAP.at(_ipVersion);
}

const std::string & Network::ServerConfig::getDomain() const {
  return _domain;
}

const Network::Ipv4 & Network::ServerConfig::getIpv4() const {
  return _ipv4;
}

const Network::Ipv6 & Network::ServerConfig::getIpv6() const {
  return _ipv6;
}

const Network::Port & Network::ServerConfig::getPort() const {
  return _port;
}

const std::string & Network::ServerConfig::getAddressStr() const {
  switch (_addressType) {
    case Network::ServerConfig::AddressType::DOMAIN:
      return _domain;
      break;
    case Network::ServerConfig::AddressType::IP:
      switch (_ipVersion) {
        case Network::ServerConfig::IpVersion::IPV4:
          return _ipv4.toString();
          break;
        case Network::ServerConfig::IpVersion::IPV6:
          return _ipv6.toString();
          break;
        default:
          throw std::runtime_error("Invalid IpVersion encountered in ServerConfig instance.");
          break;
      }
      break;
    default:
      throw std::runtime_error("Encountered invalid address type");
      break;
  }
}

/**
 * Server Configutation Builder.
 */

void Network::ServerConfigBuilder::validateStateOrThrow() const {
  if (!_hasAddress) {
    throw std::runtime_error("Must provide address to builder before constructing ServerConfig!");
  }
  if (_ipVersion == Network::ServerConfig::IpVersion::UNSPECIFIED &&
      _addressType == Network::ServerConfig::AddressType::IP) {
    throw std::runtime_error("Must specify ip version if using ip address.");
  }
  if (!_hasPort) {
    throw std::runtime_error("Must specify server port!");
  }
}

Network::ServerConfigBuilder::ServerConfigBuilder() :
    _ipVersion(Network::ServerConfig::IpVersion::UNSPECIFIED),
    _hasAddress(false),
    _hasPort(false)
{}

Network::ServerConfigBuilder & Network::ServerConfigBuilder::setIpv4(const Network::Ipv4 & ipv4) {
  _ipv4 = ipv4;
  enableIpv4();
  _addressType = Network::ServerConfig::AddressType::IP;
  return *this;
}

Network::ServerConfigBuilder & Network::ServerConfigBuilder::setIpv6(const Network::Ipv6 & ipv6) {
  _ipv6 = ipv6;
  enableIpv6();
  _addressType = Network::ServerConfig::AddressType::IP;
  return *this;
}

Network::ServerConfigBuilder & Network::ServerConfigBuilder::setPort(const Network::Port & port) {
  _port = port;
  _hasPort = true;
  return *this;
}

Network::ServerConfigBuilder & Network::ServerConfigBuilder::enableIpv4() {
  _ipVersion = Network::ServerConfig::IpVersion::IPV4;
  return *this;
}

Network::ServerConfigBuilder & Network::ServerConfigBuilder::enableIpv6() {
  _ipVersion = Network::ServerConfig::IpVersion::IPV6;
  return *this;
}

const Network::ServerConfig Network::ServerConfigBuilder::build() const {
  validateStateOrThrow();
  return Network::ServerConfig(
    _ipVersion,
    _addressType,
    _domain,
    _ipv4,
    _ipv6,
    _port
  );
}

const Network::ServerConfig * Network::ServerConfigBuilder::buildNew() const {
  validateStateOrThrow();
  return new Network::ServerConfig(
    _ipVersion,
    _addressType,
    _domain,
    _ipv4,
    _ipv6,
    _port
  );
}
