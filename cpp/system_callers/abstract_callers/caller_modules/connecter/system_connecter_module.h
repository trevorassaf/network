#pragma once

#include <system_connect_parameters>
#include <system_connect_results>
#include <system_connect_with_bind_parameters>
#include <system_connect_with_bind_results>

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
