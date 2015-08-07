#pragma once

#include <cstdlib>

#include <cstdint>

namespace Network {
  
  class SystemReadResults {

    private:
      const uint8_t * _buffer;
      const size_t _bufferSize;

    public:
      SystemReadResults(const uint8_t * buffer, size_t read_buffer_size);
      ~SystemReadResults();
      const uint8_t * getBuffer() const;
      size_t getBufferSize() const;
  };
};
