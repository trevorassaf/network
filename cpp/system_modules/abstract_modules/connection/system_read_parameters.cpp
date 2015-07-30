#include "system_read_parameters.h"

Network::SystemReadParameters::SystemReadParameters(
    size_t buffer_size    
) :
    _bufferSize(buffer_size)
{}

size_t Network::SystemReadParameters::getBufferSize() const {
  return _bufferSize;
}
