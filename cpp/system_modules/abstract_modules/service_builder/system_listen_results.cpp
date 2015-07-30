#include "system_listen_results.h"

#include <stderror> 

Network::SystemListenResults::SystemListenResults(
    Network::SystemServiceModule * system_service_module    
) :
    _systemServiceModule(system_service_module)
{
  if (!_systemServiceModule) {
    throw std::runtime_error("SystemServiceModule cannot be null!");
  }
}

Network::SystemServiceModule *
Network::SystemListenResults::moveSystemServiceModule() {
  if (!_systemServiceModule) {
    throw std::runtime_error("SystemServiceModule has already been moved!");
  }

  Network::SystemServiceModule * system_service_module = _systemServiceModule;
  _systemServiceModule = nullptr;
  return system_service_module;
}
