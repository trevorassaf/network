#pragma once

#include "network_namespace.h"

#include <cstdlib>

template <typename Tdata> class Network::Packet {

  private:
    const Tdata _data;
    const size_t _dataSize;

    Packet();
    void setData(const Tdata & data);

  public:
    Packet(const Tdata & data);
    const Tdata & getData() const;
    size_t getDataSize() const;
};
