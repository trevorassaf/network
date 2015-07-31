#include "packet_writer.h"

#include <stdexcept>

template <typename Tdata>
Network::PacketWriter<Tdata>::PacketWriter(const Network::Packet<Tdata> & packet) : 
    _packet(packet),
    _bytesRemaining(sizeof(Tdata))
{}

template <typename Tdata>
const void * Network::PacketWriter<Tdata>::serialize() const {
  return static_cast<void *>(&_packet) + _bytesRemaining;
};

template <typename Tdata>
void Network::PacketWriter<Tdata>::accumulate(size_t bytes_written) {
  if (_bytesRemaining < bytes_written) {
    throw std::runtime_error("Too many bytes written!");
  }
  _bytesRemaining -= bytes_written;
}

template <typename Tdata>
void Network::PacketWriter<Tdata>::reset() {
  _bytesRemaining = sizeof(Tdata);
}

template <typename Tdata>
bool Network::PacketWriter<Tdata>::isFinished() const {
  return _bytesRemaining == 0;
}

template <typename Tdata>
size_t Network::PacketWriter<Tdata>::getBytesRemaining() const {
  return _bytesRemaining;
}
