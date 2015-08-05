#pragma once

#include <system_modules/abstract_modules/connection/system_connection_module.h>

namespace Network {

  class SystemAcceptResults {

    private:
      const Network::SystemConnectionModule * _systemConnectionModule;

    public:
      SystemAcceptResults(
          const Network::SystemConnectionModule * system_connection_module
      );

      const Network::SystemConnectionModule * moveSystemConnectionModule();
  };
};
