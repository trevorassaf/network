#pragma once

#include <system_modules/abstract_modules/connection/system_connection_module.h>

namespace Network {
  class SystemConnectResults {
    private:
      Network::SystemConnectionModule * _systemConnectionModule;

    public:
      SystemConnectResults(
          Network::SystemConnectionModule * system_connection_module    
      );
      ~SystemConnectResults();
      Network::SystemConnectionModule * moveSystemConnectionModule();
  };
};
