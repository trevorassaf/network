#pragma once

#include <ip/host.h>
#include <ip/connecter_host_config.h>
#include <ip/address_family.h>
#include <ip/socket_type.h>

#include <system_modules/abstract_modules/connecter/system_connect_parameters.h>

namespace Network {
  class SystemConnectParametersBuilder {
    private:
      Network::Ip::Host * _remoteHost;
      Network::Ip::ConnecterHostConfig * _localHostConfig;
      Network::Ip::AddressFamily _addressFamily;
      Network::Ip::SocketType _socketType;

    public:
      SystemConnectParametersBuilder();
      ~SystemConnectParametersBuilder();
      SystemConnectParametersBuilder & setRemoteHost(
          const Network::Ip::Host & remote_host
      );
      SystemConnectParametersBuilder & setLocalHostConfig(
          const Network::Ip::ConnecterHostConfig & local_host_config
      );
      SystemConnectParametersBuilder & setAddressFamily(Network::Ip::AddressFamily address_family);
      SystemConnectParametersBuilder & setSocketType(Network::Ip::SocketType socket_type);
      Network::SystemConnectParameters build() const;
  };
};
