#include "packet_reader.h"

#include <stdexcept>

template <typename Tdata>
Network::PacketReader<Tdata>::PacketReader() :
    _bytesRead(0)
{}

template <typename Tdata>
bool Network::PacketReader<Tdata>::isFinished() const {
  return _bytesRead == sizeof(Tdata);
}

template <typename Tdata>
size_t Network::PacketReader<Tdata>::getBytesRemaining() const {
  return sizeof(Tdata) - _bytesRead;
}

template <typename Tdata>
void Network::PacketReader<Tdata>::accumulate(size_t num_bytes) {
  _bytesRead += num_bytes;
  if (_bytesRead > sizeof(Tdata)) {
    throw std::runtime_error("PacketReader buffer overflowed!");
  }
}

template <typename Tdata>
void * Network::PacketReader<Tdata>::getBuffer() {
  return static_cast<void *>(&_packet) + _bytesRead;
}

template <typename Tdata>
void Network::PacketReader<Tdata>::reset() {
  _bytesRead = 0;
}

template <typename Tdata>
const Network::Packet<Tdata> &
Network::PacketReader<Tdata>::getPacket() const {
  return _packet;  
}
