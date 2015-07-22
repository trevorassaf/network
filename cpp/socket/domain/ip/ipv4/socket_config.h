#pragma once

#include "v4_namespace.h"

#include "../../../socket_config.h"

class Network::Ip::V4::SocketConfig : Network::SocketConfig {
  public:
    virtual Network::Ip::V4::SocketConfig * setIsFreeBind(bool is_free_bind) = 0;
    virtual Network::Ip::V4::SocketConfig * enableFreeBind() = 0;
    virtual Network::Ip::V4::SocketConfig * disableFreeBind() = 0;
};
