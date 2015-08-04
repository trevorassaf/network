#include "system_write_parameters.h"

#include <stdexcept>
#include <cstring>

Network::SystemWriteParameters::SystemWriteParameters(
    const void * buffer,
    size_t buffer_size
) :
    _bufferSize(buffer_size)
{
  if (!buffer) {
    throw std::runtime_error("Write params buffer cannot be null!");
  }
  _buffer = new char[_bufferSize];
  ::memcpy(_buffer, buffer, _bufferSize);
}

Network::SystemWriteParameters::~SystemWriteParameters() {
  delete static_cast<char *>(_buffer);
  _buffer = nullptr;
}

const void * Network::SystemWriteParameters::getBuffer() const {
  return _buffer;
}

size_t Network::SystemWriteParameters::getBufferSize() const {
  return _bufferSize;
}
