#pragma once

#include <system_modules/abstract_modules/connection/system_connection_module.h>
#include <system_modules/abstract_modules/service/system_accept_results.h>
#include <ip/host.h>

namespace Network {

  class SystemAcceptResultsBuilder {

    private:
      Network::SystemConnectionModule * _systemConnectionModule;
      Network::Ip::Host * _localHost;
      Network::Ip::Host * _remoteHost;
      bool _hasAddressFamily;
      Network::Ip::AddressFamily _addressFamily;

    public:
      SystemAcceptResultsBuilder();
      ~SystemAcceptResultsBuilder();

      SystemAcceptResultsBuilder & setSystemConnectionModule(
          Network::SystemConnectionModule * system_connection_module    
      );

      SystemAcceptResultsBuilder & setLocalHost(
          const Network::Ip::Host & local_host    
      );
      
      SystemAcceptResultsBuilder & setRemoteHost(
          const Network::Ip::Host & remote_host    
      );

      SystemAcceptResultsBuilder & setAddressFamily(
          Network::Ip::AddressFamily address_family    
      );

      Network::SystemAcceptResults * build();
  };
};
