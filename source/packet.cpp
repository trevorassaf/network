#include "../headers/packet.h"

template <class Tdata> 
Network::Packet<Tdata>::Packet() : 
    _dataSize(sizeof(Tdata))
{}

template <class Tdata>
Tdata & Network::Packet<Tdata>::getData() {
  return _data;
}

template <class Tdata>
Network::Packet<Tdata>::Packet(const Tdata & data) :
    _data(data),
    _dataSize(sizeof(Tdata))
{}

template <class Tdata>
const Tdata & Network::Packet<Tdata>::getData() const {
  return _data;
}

template <class Tdata>
size_t Network::Packet<Tdata>::getSize() const {
  return _dataSize;
}
