#pragma once

#include <system_modules/abstact_modules/service_builder/system_listen_parameters.h>
#include <system_modules/abstact_modules/service_builder/system_listen_results.h>

namespace Network {
  
  class Network::SystemServiceBuilderModule {

    public:
      virtual const Network::SystemListenResults * listen(
          const Network::SystemListenParameters * listen_params    
      ) = 0;
  };
};
