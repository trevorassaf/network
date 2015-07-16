#pragma once

#include "socket_builder.h"
#include "socket.h"

class Network::Ip::Tcp::ServiceBuilder :
    public Network::Ip::Tcp::SocketBuilder {};
