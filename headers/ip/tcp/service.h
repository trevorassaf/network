#pragma once

#include "service.h"

class Network::Ip::Tcp::Service :
    public Network::Ip::Tcp::Socket {

  private:
    const unsigned int _backlogSize;
    const Network::Host _host;
    
    friend class ServiceBuilder;
    Service();

  public:

    unsigned int getBacklogSize() const;
    const Network::Host & getHost() const;
    Network::Connection * accept() const;
};
