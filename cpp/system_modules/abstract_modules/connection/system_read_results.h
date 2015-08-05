#pragma once

#include <cstdlib>

namespace Network {
  
  class SystemReadResults {

    private:
      void * _buffer;
      const size_t _bufferSize;

    public:
      SystemReadResults(const void * buffer, size_t read_buffer_size);
      ~SystemReadResults();
      template <typename T> T deserialize() const;
      size_t getBufferSize() const;
  };
};
