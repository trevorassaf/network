#pragma once

#include "socket_config.h"
#include "../socket_builder.h"

class Network::Ip::Tcp::SocketBuilder :
    public Network::Ip::Tcp::SocketConfig,
    public Network::Ip::SocketBuilder {
    
};
