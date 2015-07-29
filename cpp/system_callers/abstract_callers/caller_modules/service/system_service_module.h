#pragma once

#include <system_accept_results>

namespace Network {
  
  class Network::SystemServiceModule {

    public:
      virtual const Network::SystemAcceptResults * accept() = 0;
      
      virtual void close() = 0;
  };
};
