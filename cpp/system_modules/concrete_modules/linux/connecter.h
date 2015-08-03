#pragma once

#include <system_modules/abstract_modules/connecter/system_connecter_module.h>
#include <system_modules/abstract_modules/connecter/system_connect_parameters.h>
#include <system_modules/abstract_modules/connecter/system_connect_results.h>
#include <system_modules/abstract_modules/connecter/system_connect_with_bind_parameters.h>
#include <system_modules/abstract_modules/connecter/system_connect_with_bind_results.h>

namespace Network {
  namespace Linux {  
    class Connecter : public Network::SystemConnecterModule {
      public:
        const Network::SystemConnectResults * connect(
            const Network::SystemConnectParameters & system_connect_parameters    
        );

        const Network::SystemConnectWithBindResults * connect(
            const Network::SystemConnectWithBindParameters & system_connect_parameters    
        );
    };
  };
};
