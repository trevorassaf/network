#pragma once

#include "network.h"

#include "packet.h"

#include <cstdlib>
#include <cstdint>

template <class Tdata> class Network::PacketReader {

  private:
    Network::Packet<Tdata> _packet;
    size_t _bytesRemaining;
    uint8_t * _buffer;

  public:
    PacketReader();
    bool isFinished() const;
    size_t getBytesRemaining() const;
    void accumulate(size_t);
    void * getBuffer();
    void reset();
    const Packet<Tdata> & getPacket() const;
};
