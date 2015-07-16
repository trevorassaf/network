#pragma once

#include "socket_builder.h"
#include "connection.h"
#include "../../host.h"
#include "../../socket_config.h"

class Network::Ip::Tcp::ConnectionBuilder :
    public Network::Ip::Tcp::SocketBuilder {

  private:
    bool _isLocalHostSet;
    Network::HostBuilder _localHostBuilder;

    bool _isRemoteHostSet;
    Network::HostBuilder _remoteHostBuilder;
  
  protected:
    Network::Tcp::Ip::Connection * initNewConcreteSocket(int opened_socket_descriptor) const;

  public:
    ConnectionBuilder();

    Network::SocketConfig::Type getType() override const;
    Network::SocketConfig::AddressFamily getAddressFamily() override const;
    Network::Tcp::Ip::Connection * build() const;    
};
