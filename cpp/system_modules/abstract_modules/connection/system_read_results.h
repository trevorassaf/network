#pragma once

#include <cstdlib>

namespace Network {
  
  class SystemReadResults {

    private:
      void * _buffer;
      size_t _bufferSize;

    public:
      SystemReadResults(size_t read_buffer_size);
      ~SystemReadResults();
      const void * getBuffer() const;
      void * getBuffer();
      size_t getBufferSize() const;
  };
};
