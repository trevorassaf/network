#pragma once

#include <cstdlib>

namespace Network {
  
  class SystemReadResults {

    private:
      void * _buffer;
      const size_t _bufferSize;

    public:
      SystemReadResults(const void * buffer, size_t read_buffer_size);
      SystemReadResults(const SystemReadResults & results) = delete;
      SystemReadResults & operator=(const SystemReadResults & results) = delete;
      ~SystemReadResults();
      template <typename T> T deserialize() const;
      size_t getBufferSize() const;
  };
};
