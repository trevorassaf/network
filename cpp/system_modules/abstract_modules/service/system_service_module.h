#pragma once

#include <system_modules/abstract_modules/service/system_accept_results.h>
#include <ip/host.h>
#include <string>
#include <vector>

namespace Network {
  
  class SystemServiceModule {

    public:
      virtual Network::SystemAcceptResults accept() = 0;
      
      typedef std::vector<Network::Ip::Host> ListeningHosts;
      virtual const ListeningHosts & getListeningHosts() const = 0; 
      
      virtual void close() = 0;
      
      virtual ~SystemServiceModule() {}
  };
};
