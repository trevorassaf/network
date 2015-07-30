#pragma once

#include <system_modules/abstract_modules/connecter/system_connect_parameters.h>
#include <system_modules/abstract_modules/connecter/system_connect_results.h>
#include <system_modules/abstract_modules/connecter/system_connect_with_bind_parameters.h>
#include <system_modules/abstract_modules/connecter/system_connect_with_bind_results.h>

namespace Network {
  
  class Network::SystemConnecterModule {

    public:
      virtual const Network::SystemConnectResults * connect(
          const Network::SystemConnectParameters * system_connect_parameters    
      ) = 0;

      virtual const Network::SystemConnectWithBindResults * connect(
          const Network::SystemConnectWithBindParameters * system_connect_parameters    
      ) = 0;
  };

};
