#include "packet.h"

template <typename Tdata>
Network::Packet<Tdata>::Packet() :
    _dataSize(sizeof(Tdata))
{}

template <typename Tdata>
void Network::Packet<Tdata>::setData(const Tdata & data) {
  _data = data;
}

template <typename Tdata>
Network::Packet<Tdata>::Packet(const Tdata & data) :
    _data(data),
    _dataSize(sizeof(data))
{}

template <typename Tdata>
const Tdata & Network::Packet<Tdata>::getData() const {
  return _data;
}

template <typename Tdata>
size_t Network::Packet<Tdata>::getDataSize() const {
  return _dataSize;
}
