#pragma once

#include <system_modules/abstract_modules/service/system_service_module.h>

namespace Network {
  class SystemListenResults {

    private:
      Network::SystemServiceModule * _systemServiceModule; 

    public:
      SystemListenResults(Network::SystemServiceModule * system_service_module);
      Network::SystemServiceModule * moveSystemServiceModule();
  };
};
