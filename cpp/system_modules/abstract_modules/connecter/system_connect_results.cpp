#include "system_connect_results.h"

#include <stdexcept>

Network::SystemConnectResults::SystemConnectResults(
    Network::SystemConnectionModule * system_connection_module    
) :
    _systemConnectionModule(system_connection_module)
{}

Network::SystemConnectResults::~SystemConnectResults() {
  delete _systemConnectionModule;
  _systemConnectionModule = nullptr;
}

Network::SystemConnectionModule * Network::SystemConnectResults::moveSystemConnectionModule() {
  if (!_systemConnectionModule) {
    throw std::runtime_error("Connection already moved!");
  }
  Network::SystemConnectionModule * temp = _systemConnectionModule;
  _systemConnectionModule = nullptr;
  return temp;
}
