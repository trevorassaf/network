#pragma once

#include <cstdlib>

namespace Network {
  
  class SystemWriteParameters {

    private:
      const void * _buffer;
      size_t _bufferSize;

    public:
      SystemWriteParameters(
          const void * buffer,
          size_t buffer_size
      );
      const void * getBuffer() const;
      size_t getBufferSize() const;
  };
};
