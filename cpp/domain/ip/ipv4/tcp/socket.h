#pragma once

#include "socket_config.h"
#include "../socket.h"

class Network::Ip::Tcp::Socket :
    public Network::Ip::Tcp::SocketConfig,
    public Network::Ip::Socket {
    
};
