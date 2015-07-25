#pragma once

#include "network_namespace.h"
#include "../../../packets/packet.h"

#include <sys/types.h>
#include <sys/socket.h>

template <typename Tdata>
class Network::SystemReadResults {

  private:
    const Network::Packet<Tdata> * _packet;

  public:
    SystemReadResults(
        const Network::Packet<Tdata> * packet
    );

    const Network::Packet<Tdata> * getPacket() const;
};
