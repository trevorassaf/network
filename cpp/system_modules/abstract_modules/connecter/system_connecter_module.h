#pragma once

#include <system_modules/abstract_modules/connecter/system_connect_parameters.h>
#include <system_modules/abstract_modules/connecter/system_connect_results.h>

namespace Network {
  
  class SystemConnecterModule {

    public:
      virtual const Network::SystemConnectResults connect(
          const Network::SystemConnectParameters & connect_parameters    
      ) = 0;

      virtual ~SystemConnecterModule() {}
  };
};
