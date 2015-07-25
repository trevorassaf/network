#pragma once

#include "network_namespace.h"

#include <sys/types.h>
#include <sys/socket.h>

template <typename Tdata>
class Network::SystemWriteParameters {

  private:
    const Network::Packet<Tdata> * _packet;

  public:
    SystemWriteParameters(
        const Network::Packet<Tdata> * packet
    );

    const Network::Packet<Tdata> * getPacket() const;
};
