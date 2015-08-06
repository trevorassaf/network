#include "system_accept_results.h"

#include <stdexcept>

Network::SystemAcceptResults::SystemAcceptResults(
    Network::SystemConnectionModule * system_connection_module
) :
    _systemConnectionModule(system_connection_module)
{
  if (!_systemConnectionModule) {
    throw std::runtime_error("System conneciton module can't be null!");
  }
}

Network::SystemConnectionModule *
Network::SystemAcceptResults::moveSystemConnectionModule() {
  if (!_systemConnectionModule) {
    throw std::runtime_error("Already moved system connection module!");
  }

  Network::SystemConnectionModule * temporary_system_connection_module = _systemConnectionModule;
  _systemConnectionModule = nullptr;
  return temporary_system_connection_module;
}
