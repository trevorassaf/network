#pragma once

#include <system_modules/abstract_modules/service/system_accept_results.h>
#include <string>
#include <vector>

namespace Network {
  
  class SystemServiceModule {

    public:
      virtual const Network::SystemAcceptResults * accept() = 0;
      
      typedef std::vector<const Network::Ip::Address> ListeningHosts;
      virtual const ListeningHosts & getListeningHosts() const = 0; 
      
      virtual void close() = 0;
  };
};
