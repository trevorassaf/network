#pragma once

#include "v4_namespace.h"
#include "socket_config.h"
#include "socket.h"
#include "../../../socket_builder.h"

class Network::Ip::V4::SocketBuilder :
      public Network::SocketBuilder, 
      public Network::Ip::V4::SocketConfig {

  private:
    bool _isFreeBindSet, _isFreeBind;

  public:
    Network::Ip::V4::SocketBuilder * setIsFreeBind(bool is_free_bind) override;
    Network::Ip::V4::SocketBuilder * enableFreeBind() override;
    Network::Ip::V4::SocketBuilder * disableFreeBind() override;
    
    virtual Network::Ip::V4::Socket * build() const override;
};
