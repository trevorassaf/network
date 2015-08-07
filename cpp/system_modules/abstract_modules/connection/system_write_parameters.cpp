#include "system_write_parameters.h"

#include <stdexcept>
#include <cstring>

Network::SystemWriteParameters::SystemWriteParameters(
    const uint8_t * buffer,
    size_t buffer_size
) :
    _buffer(buffer),
    _bufferSize(buffer_size)
{}

const uint8_t * Network::SystemWriteParameters::getBuffer() const {
  return _buffer;
}

size_t Network::SystemWriteParameters::getBufferSize() const {
  return _bufferSize;
}
