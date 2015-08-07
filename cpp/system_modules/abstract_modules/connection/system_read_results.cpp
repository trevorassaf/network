#include "system_read_results.h"

#include <stdexcept>
#include <cstring>

Network::SystemReadResults::SystemReadResults(
    const uint8_t * buffer,
    size_t buffer_size
) : 
    _buffer(buffer),
    _bufferSize(buffer_size)
{
  if (!buffer && _bufferSize) {
    throw std::runtime_error("Buffer can't be null and have a non-zero buffer size!");
  }
}

Network::SystemReadResults::~SystemReadResults() {
  delete[] _buffer;
  _buffer = nullptr;
}

const uint8_t * Network::SystemReadResults::getBuffer() const {
  return _buffer;
}

size_t Network::SystemReadResults::getBufferSize() const {
  return _bufferSize;
}
