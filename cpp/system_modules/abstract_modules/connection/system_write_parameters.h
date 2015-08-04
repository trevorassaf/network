#pragma once

#include <cstdlib>

namespace Network {
  
  class SystemWriteParameters {

    private:
      const void * _buffer;
      const size_t _bufferSize;

    public:
      SystemWriteParameters(
          const void * buffer,
          size_t buffer_size
      );
      SystemWriteParameters(const SystemWriteParameters & parameters) = delete;
      SystemWriteParameters & operator=() = delete;
      ~SystemWriteParameters();
      const void * getBuffer() const;
      size_t getBufferSize() const;
  };
};
