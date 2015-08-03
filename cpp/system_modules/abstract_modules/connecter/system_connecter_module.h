#pragma once

#include <system_modules/abstract_modules/connecter/system_connect_parameters.h>
#include <system_modules/abstract_modules/connecter/system_connect_results.h>
#include <system_modules/abstract_modules/connecter/system_connect_with_bind_parameters.h>

namespace Network {
  
  class Network::SystemConnecterModule {

    public:
      virtual const Network::SystemConnectResults * connect(
          const Network::SystemConnectParameters & connect_parameters    
      ) = 0;

      virtual const Network::SystemConnectResults * connect(
          const Network::SystemConnectWithBindParameters & connect_parameters    
      ) = 0;
  };

};
