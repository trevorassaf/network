#pragma once

#include "../network.h"
#include "../socket.h"
#include "socket_config.h"

class Network::Ip::Socket :
    public Network::Socket,
    public Network::Ip::SocketConfig {

};
