#include "system_write_parameters.h"

Network::SystemWriteParameters::SystemWriteParameters(
    const void * buffer,
    size_t buffer_size
) :
    _buffer(buffer),
    _bufferSize(buffer_size)
{}

const void * Network::SystemWriteParameters::getBuffer() const {
  return _buffer;
}

size_t Network::SystemWriteParameters::getBufferSize() const {
  return _bufferSize;
}
