#pragma once

#include "socket_builder.h"
#include "service.h"
#include "../../socket_config.h"
#include "../../host.h"

#define DEFAULT_BACKLOG_SIZE 10

class Network::Ip::Tcp::ServiceBuilder :
    public Network::Ip::Tcp::SocketBuilder {

  private:
    bool _isHostSet;
    Network::HostBuilder _hostBulder;

    unsigned int _backlogSize;
   
  protected:
    Network::Tcp::Ip::Service * initNewConcreteSocket(int opened_socket_descriptor) const;

  public:
    ServiceBuilder();

    Network::SocketConfig::Type getType() override const;
    Network::SocketConfig::AddressFamily getAddressFamily() override const;
    Network::Tcp::Ip::Service * build() const;

    ServiceBuilder & setHost(const Network::Host & host);
    ServiceBuilder & setBacklogSize(unsigned int backlog_size);
};
