#include "system_read_results.h"

Network::SystemReadResults::SystemReadResults(
    const void * buffer,
    size_t buffer_size
) : 
    _bufferSize(buffer_size)
{
  if (!buffer && _bufferSize) {
    throw std::runtime_error("Buffer can't be null and have a non-zero buffer size!");
  }

  if (!_bufferSize) {
    _buffer = nullptr;
  }
 
  _buffer = new char[_bufferSize];
  ::memcpy(_buffer, buffer, _bufferSize);
}

Network::SystemReadResults::~SystemReadResults() {
  delete[] _buffer; 
  _buffer = nullptr;
}

template <typename T> Network::SystemReadResults::deserialize<T>() const {
  if (sizeof(T) != _bufferSize) {
    throw std::runtime_error("Read results buffer size does not equal T size");
  }
  T t;
  ::memcpy(&t, _buffer, _bufferSize);
  return t;
}

size_t Network::SystemReadResults::getBufferSize() const {
  return _bufferSize;
}
