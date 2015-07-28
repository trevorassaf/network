#pragma once

#include "linux_namespace.h"
#include "../../abstract_callers/caller_modules/service_builder/system_service_builder_module.h"

class Network::Linux::ServiceBuilder : Network::SystemServiceModule {

  public:
    const Network::SystemListenResults * listen(
        const Network::SystemListenParameters * listen_params    
    ) override; 
};
