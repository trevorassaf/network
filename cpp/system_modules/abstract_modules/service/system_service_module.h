#pragma once

#include <system_modules/abstract_modules/service/system_accept_results.h>

namespace Network {
  
  class Network::SystemServiceModule {

    public:
      virtual const Network::SystemAcceptResults * accept() = 0;
      
      virtual void close() = 0;
  };
};
