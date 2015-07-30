#pragma once

#include <system_service_module>

class Network::SystemListenResults {

  private:
    Network::SystemServiceModule * _systemServiceModule; 

  public:
    Network::SystemListenResults(
        Network::SystemServiceModule * system_service_module    
    );
    Network::SystemServiceModule * moveSystemServiceModule();
};
