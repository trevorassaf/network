#pragma once

#include <system_modules/abstract_modules/connection/system_connection_module.h>

namespace Network {

  class SystemAcceptResults {

    private:
      Network::SystemConnectionModule * _systemConnectionModule;

    public:
      SystemAcceptResults(
          Network::SystemConnectionModule * system_connection_module
      );

      Network::SystemConnectionModule * moveSystemConnectionModule();
  };
};
