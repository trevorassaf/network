#pragma once

#include "network.h"

#include "packet.h"

#include <cstdlib>
#include <cstdint>

template <class Tdata> class Network::PacketWriter {

  private:
    const Network::Packet<Tdata> _packet;
    size_t _bytesRemaining;
    const uint8_t * _buffer;
  public:
    PacketWriter(const Network::Packet<Tdata> packet);
    const void * serialize() const;
    void accumulate(size_t bytes_written);
    void reset();
    bool isFinished() const;
    size_t getBytesRemaining() const;
};
