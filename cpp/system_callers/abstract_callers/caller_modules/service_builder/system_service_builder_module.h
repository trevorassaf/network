#pragma once

#include "network_namespace.h"
#include "system_listen_parameters.h"
#include "system_listen_results.h"

class Network::SystemServiceBuilderModule {

  public:
    virtual const Network::SystemListenResults * listen(
        const Network::SystemListenParameters * listen_params    
    ) = 0;

};
