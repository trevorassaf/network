#pragma once

#include <packets/packet.h>

#include <cstdlib>
#include <cstdint>

namespace Network {
  template <class Tdata> class PacketWriter {

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
};
