#pragma once

#include "network.h"
#include "packet_writer.h"

#include <cstdlib>

template <class Tdata> class Network::Packet {

  private:
    
    friend class Network::PacketWriter<Tdata>;
    
    Tdata _data;
    size_t _dataSize;

    Packet();
    Tdata & getData();

  public:
    Packet(const Tdata & data);
    const Tdata & getData() const;
    size_t getSize() const;
};
