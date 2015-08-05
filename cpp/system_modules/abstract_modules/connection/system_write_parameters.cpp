#include "system_write_parameters.h"

#include <stdexcept>
#include <cstring>

template <typename T>
Network::SystemWriteParameters::SystemWriteParameters(
    const T & t
) :
    _bufferSize(sizeof(t))
{
  _buffer = new uint8_t[_bufferSize];
  ::memcpy(
      _buffer,
      static_cast<const uint8_t *>(&t),
      _bufferSize
  );
}

Network::SystemWriteParameters::~SystemWriteParameters() {
  delete static_cast<uint8_t *>(_buffer);
  _buffer = nullptr;
}

const uint8_t * Network::SystemWriteParameters::getBuffer() const {
  return _buffer;
}

size_t Network::SystemWriteParameters::getBufferSize() const {
  return _bufferSize;
}
