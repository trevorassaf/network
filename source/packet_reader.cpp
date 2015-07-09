#include "../headers/packet_reader.h"

#include "../headers/network_except.h"

#include <stdexcept>

template <class Tdata>
Network::PacketReader<Tdata>::PacketReader() : 
    _packet(),
    _bytesRemaining(_packet.getSize()),
    _buffer(static_cast<uint8_t *>(_packet.getData()))
{}

template <class Tdata>
bool Network::PacketReader<Tdata>::isFinished() const {
  return !_bytesRemaining;
}

template <class Tdata>
size_t Network::PacketReader<Tdata>::getBytesRemaining() const {
  return _bytesRemaining;
}

template <class Tdata>
void Network::PacketReader<Tdata>::accumulate(size_t bytes_read) {
  if (bytes_read > _bytesRemaining) {
    throw std::runtime_error(
        std::string("Can't accumulate more data than Tdata can accomodate! ") +
        std::string("Bytes read: ") + std::to_string(bytes_read) +
        std::string(". Bytes remaining: ") + std::to_string(_bytesRemaining)
    );
  }
  _bytesRemaining -= bytes_read;
  _buffer += bytes_read;
}

template <class Tdata>
void * Network::PacketReader<Tdata>::getBuffer() {
  if (isFinished()) {
    throw std::runtime_error("Can't getBuffer() because we've finished reading!");
  }
  return _buffer;
}

template <class Tdata>
void Network::PacketReader<Tdata>::reset() {
  _bytesRemaining = _packet.getSize();
  _buffer = static_cast<uint8_t *>(_packet.getData());
}

template <class Tdata>
const Network::Packet<Tdata> & Network::PacketReader<Tdata>::getPacket() const {
  return _packet;
}
