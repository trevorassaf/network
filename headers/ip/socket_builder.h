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
    virtual Network::Ip::Socket * build() const override = 0;
    int openIpSocket() const;

  public:
    virtual Network::SocketConfig::Type
        getType() const override = 0;
    
    virtual Network::SocketConfig::AddressFamily
        getAddressFamily() const override = 0;
};
