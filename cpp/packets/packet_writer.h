#pragma once

#include "../network_namespace.h"

#include "packet.h"

#include <cstdlib>
#include <cstdint>

template <class Tdata> class Network::PacketWriter {

  private:
    const Network::Packet<Tdata> & _packet;
    size_t _bytesRemaining;

  public:
    PacketWriter(const Network::Packet<Tdata> & packet);
    const void * serialize() const;
    void accumulate(size_t bytes_written);
    void reset();
    bool isFinished() const;
    size_t getBytesRemaining() const;
};
