#pragma once

#include <system_listen_parameters>
#include <system_listen_results>

namespace Network {
  
  class Network::SystemServiceBuilderModule {

    public:
      virtual const Network::SystemListenResults * listen(
          const Network::SystemListenParameters * listen_params    
      ) = 0;
  };
};
