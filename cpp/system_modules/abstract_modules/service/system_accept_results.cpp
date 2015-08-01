#include "system_accept_results.h"

#include <stdexcept>

Network::SystemAcceptResults::SystemAcceptResults(
    const Network::SystemConnectionModule * system_connection_module,
    const Network::Ip::Host & local_host,
    const Network::Ip::Host & remote_host,
    Network::Ip::AddressFamily address_family
) :
    _systemConnectionModule(system_connection_module),
    _localHost(local_host),
    _remoteHost(remote_host),
    _addressFamily(address_family)
{
  if (!_systemConnectionModule) {
    throw std::runtime_error("System conneciton module can't be null!");
  }
}

const Network::SystemConnectionModule *
Network::SystemAcceptResults::moveSystemConnectionModule() {
  if (!_systemConnectionModule) {
    throw std::runtime_error("Already moved system connection module!");
  }

  const Network::SystemConnectionModule * temporary_system_connection_module = _systemConnectionModule;
  _systemConnectionModule = nullptr;
  return temporary_system_connection_module;
}

const Network::Ip::Host &
Network::SystemAcceptResults::getLocalHost() const {
  return _localHost;
}

const Network::Ip::Host &
Network::SystemAcceptResults::getRemoteHost() const {
  return _remoteHost;
}

const Network::Ip::AddressFamily
Network::SystemAcceptResults::getAddressFamily() const {
  return _addressFamily;
}
