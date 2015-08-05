#pragma once

#include <cstdlib>
#include <cstdint>

namespace Network {
  
  class SystemWriteParameters {

    private:
      uint8_t * _buffer;
      const size_t _bufferSize;

    public:
      template <typename T> SystemWriteParameters(const T & t);
      ~SystemWriteParameters();
      const uint8_t * getBuffer() const;
      size_t getBufferSize() const;
  };
};
