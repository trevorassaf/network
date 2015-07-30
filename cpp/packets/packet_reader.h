#pragma once

#include <packets/packet.h>

#include <cstdlib>
#include <cstdint>

namespace Network {
  
  template <class Tdata> class PacketReader {

    private:
      Network::Packet<Tdata> _packet;
      size_t _bytesRead;

    public:
      PacketReader();
      bool isFinished() const;
      size_t getBytesRemaining() const;
      void accumulate(size_t num_bytes);
      void * getBuffer();
      void reset();
      const Packet<Tdata> & getPacket() const;
  };
};
