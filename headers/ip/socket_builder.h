#pragma once

#include "../network.h"
#include "../socket_builder.h"
#include "../socket.h"
#include "../socket_config.h"
#include "socket_config.h"

class Network::Ip::SocketBuilder : 
    public Network::SocketBuilder,
    public Network::Ip::SocketConfig {
  
  protected: 
    virtual Network::Socket *
    initNewConcreteSocket(
        int socket_descriptor
    ) const override = 0;

  public:
    virtual Network::SocketConfig::Type
    getType() const override = 0;
    
    virtual Network::SocketConfig::AddressFamily
    getAddressFamily() const override = 0;
};
