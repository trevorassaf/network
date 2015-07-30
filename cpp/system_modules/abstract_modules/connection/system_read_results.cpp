#include "system_read_results.h"

Network::SystemReadResults::SystemReadResults(
    size_t buffer_size
) : 
    _buffer(new char[buffer_size]),
    _bufferSize(buffer_size)
{}

Network::SystemReadResults::~SystemReadResults() {
  delete[] _buffer; 
}

const void * Network::SystemReadResults::getBuffer() const {
  return _buffer;
}

void * Network::SystemReadResults::getBuffer() {
  return _buffer;
}

size_t Network::SystemReadResults::getBufferSize() const {
  return _bufferSize;
}
