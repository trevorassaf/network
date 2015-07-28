#pragma once

#include "network_namespace.h"

class Network::SystemListenResults {

  private:
    Network::SystemServiceModule * _systemServiceModule; 

  public:
    Network::SystemListenResults(
        Network::SystemServiceModule * system_service_module    
    );
    Network::SystemServiceModule * moveSystemServiceModule();
};
