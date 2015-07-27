#pragma once

#include "network_namespace.h"
#include "../listener/system_listener.h"
#include "../listener/system_listen_parameters.h"
#include "../listener/system_listen_results.h"

class Network::SystemServiceModule {

  public:
    virtual const Network::SystemListenResults * listen(
        const Network::SystemListenParameters * listen_params    
    ) = 0;

};
