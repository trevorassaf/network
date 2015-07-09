#pragma once

#include "network.h"

#include <cstdlib>

template <class Tdata> class Network::Packet {

  private:
    Tdata _data;
    size_t _dataSize;
    size_t _bytesRemaining;

  public:
    Packet();
    Packet(const Tdata & data);
    const Tdata & getData() const;
    void accumulate(const void * data, size_t num_bytes);
    const void * serialize() const;
    bool isFull() const;
    size_t getSize() const;
    size_t getBytesRemaining() const;
};
