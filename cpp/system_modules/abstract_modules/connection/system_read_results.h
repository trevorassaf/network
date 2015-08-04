#pragma once

#include <cstdlib>

namespace Network {
  
  class SystemReadResults {

    private:
      const void * _buffer;
      const size_t _bufferSize;

    public:
      SystemReadResults(void * buffer, size_t read_buffer_size);
      SystemReadResults(const SystemReadResults & results) = delete;
      SystemReadResults & operator=(const SystemReadResults & results) = delete;
      ~SystemReadResults();
      template <typename T> T deserialize<T>() const;
      size_t getBufferSize() const;
  };
};
