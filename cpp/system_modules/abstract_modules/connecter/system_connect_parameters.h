#pragma once

#include <ip/host.h>
#include <ip/connecter_host_config.h>
#include <ip/address_family.h>
#include <ip/socket_type.h>

namespace Network {
  class SystemConnectParameters {
    private:
      const Network::Ip::Host _remoteHost;
      const Network::Ip::ConnecterHostConfig * _localHostConfig;
      const Network::Ip::AddressFamily _addressFamily;
      const Network::Ip::SocketType _socketType;

    public:
      SystemConnectParameters(
          const Network::Ip::Host & remote_host,
          const Network::Ip::ConnecterHostConfig * local_host_config,
          Network::Ip::AddressFamily address_family,
          Network::Ip::SocketType socket_type 
      );
      SystemConnectParameters(const SystemConnectParameters & parameters);
      SystemConnectParameters & operator=(const SystemConnectParameters & parameters);
      ~SystemConnectParameters();
      const Network::Ip::Host & getRemoteHost() const;
      bool hasLocalHostConfig() const;
      const Network::Ip::ConnecterHostConfig & getLocalHostConfig() const;
      Network::Ip::AddressFamily getAddressFamily() const;
      Network::Ip::SocketType getSocketType() const;
  };
};
