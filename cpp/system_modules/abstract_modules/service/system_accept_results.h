#pragma once

#include <system_modules/abstract_modules/connection/system_connection_module.h>
#include <ip/host.h>
#include <ip/address_family.h>

namespace Network {

  class SystemAcceptResults {

    private:
      const Network::SystemConnectionModule * _systemConnectionModule;
      const Network::Ip::Host _localHost;
      const Network::Ip::Host _remoteHost;
      const Network::Ip::AddressFamily _addressFamily;

    public:
      SystemAcceptResults(
          const Network::SystemConnectionModule * system_connection_module,
          const Network::Ip::Host & local_host,
          const Network::Ip::Host & remote_host,
          Network::Ip::AddressFamily address_family
      );

      const Network::SystemConnectionModule * moveSystemConnectionModule();
      const Network::Ip::Host & getLocalHost() const;
      const Network::Ip::Host & getRemoteHost() const;
      const Network::Ip::AddressFamily getAddressFamily() const;
  };
};
