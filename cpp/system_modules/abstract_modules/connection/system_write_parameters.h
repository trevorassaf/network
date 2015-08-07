#pragma once

#include <cstdlib>
#include <cstdint>

namespace Network {
  
  class SystemWriteParameters {

    private:
      const uint8_t * _buffer;
      const size_t _bufferSize;

    public:
      SystemWriteParameters(
          const uint8_t * buffer,
          size_t buffer_size
      );
      const uint8_t * getBuffer() const;
      size_t getBufferSize() const;
  };
};
