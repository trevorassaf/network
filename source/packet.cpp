#include "../headers/packet.h"

#include <stdexcept>
#include <cstring>

template <class Tdata> 
Network::Packet<Tdata>::Packet() : 
    _dataSize(sizeof(Tdata)),
    _bytesRemaining(_dataSize)
{}

template <class Tdata>
Network::Packet<Tdata>::Packet(const Tdata & data) :
    _data(data),
    _dataSize(sizeof(Tdata)),
    _bytesRemaining(0)
{}

template <class Tdata>
const Tdata & Network::Packet<Tdata>::getData() const {
  if (_bytesRemaining) {
    throw std::runtime_error(
        std::string("Can't call getData() until we've accumulated the entire packet! Num bytes remaining: ") +
        std::to_string(_bytesRemaining)
    );
  }  
  return _data;
}

template <class Tdata>
void Network::Packet<Tdata>::accumulate(const void * data, size_t num_bytes) {
  if (num_bytes > _bytesRemaining) {
    throw std::runtime_error(
        std::string("Reading too much data into packet!") +
        std::to_string(num_bytes - _bytesRemaining)
    );
  }
  std::memcpy(
      static_cast<void *>(&_data) + _bytesRemaining,
      data,
      num_bytes
  );
  _bytesRemaining -= num_bytes;
}

template <class Tdata>
const void * Network::Packet<Tdata>::serialize() const {
  if (_bytesRemaining) {
    throw std::runtime_error(
        std::string("Can't call serialize() until we've accumulated the entire packet! Num bytes remaining: ") +
        std::to_string(_bytesRemaining)
    );
  }
  return static_cast<void *>(&_data);
}

template <class Tdata>
bool Network::Packet<Tdata>::isFull() const {
  return !_bytesRemaining;
}

template <class Tdata>
size_t Network::Packet<Tdata>::getSize() const {
  return _dataSize;
}

template <class Tdata>
size_t Network::Packet<Tdata>::getBytesRemaining() const {
  return _bytesRemaining;
}
