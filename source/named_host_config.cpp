#include "../headers/named_host_config.h"

#include <cassert>
#include <netinet/in.h>
#include <sys/socket.h>
#include <stdexcept>


Network::NamedHostConfig::NamedHostConfig() :
    Network::HostConfig(), _hasDomain(false)
{}

bool Network::NamedHostConfig::hasDomain() const {
  return _hasDomain;
}

Network::NamedHostConfig & Network::NamedHostConfig::setDomain(const std::string & domain) {
  _hasDomain = true;
  _domain = domain;
  return *this;
}

Network::NamedHostConfig & Network::NamedHostConfig::unsetDomain() {
  _hasDomain = false;
  return *this;
}

const std::string & Network::NamedHostConfig::getDomain() const {
  if (!_hasDomain) {
    throw std::runtime_error("Domain name must be set before this function is invoked!");
  }
  return _domain;
}
