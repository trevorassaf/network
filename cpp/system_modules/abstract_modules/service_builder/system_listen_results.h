#pragma once

#include <system_modules/abstact_modules/service_builder/system_service_module.h>

class Network::SystemListenResults {

  private:
    Network::SystemServiceModule * _systemServiceModule; 

  public:
    Network::SystemListenResults(
        Network::SystemServiceModule * system_service_module    
    );
    Network::SystemServiceModule * moveSystemServiceModule();
};
