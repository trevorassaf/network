#include "../headers/packet_writer.h"

#include <stdexcept>

template <class Tdata>
Network::PacketWriter<Tdata>::PacketWriter(
    const Network::Packet<Tdata> packet
) :
    _packet(packet),
    _bytesRemaining(packet.getSize()),
    _buffer(static_cast<const uint8_t *>(&_packet.getData()))
{}

template <class Tdata>
const void * Network::PacketWriter<Tdata>::serialize() const {
  if (!_bytesRemaining) {
    throw std::runtime_error("Can't serialize when bytes-remaining is 0!");
  }
  return static_cast<const void *>(_buffer);
}

template <class Tdata>
void Network::PacketWriter<Tdata>::accumulate(size_t bytes_written) {
  if (bytes_written > _bytesRemaining) {
    throw std::runtime_error(
        std::string("Can't accumulate more data than Tdata can accomodate! ") +
        std::string("Bytes written: ") + std::to_string(bytes_written) +
        std::string(". Bytes remaining: ") + std::to_string(_bytesRemaining)
    );
  }
  _bytesRemaining -= bytes_written;
  _buffer += bytes_written;
}

template <class Tdata>
void Network::PacketWriter<Tdata>::reset() {
  _bytesRemaining = _packet.getSize();
  _buffer = static_cast<const uint8_t *>(&_packet.getData());
}

template <class Tdata>
bool Network::PacketWriter<Tdata>::isFinished() const {
  return !_bytesRemaining;
}

template <class Tdata>
size_t Network::PacketWriter<Tdata>::getBytesRemaining() const {
  return _bytesRemaining;
}
