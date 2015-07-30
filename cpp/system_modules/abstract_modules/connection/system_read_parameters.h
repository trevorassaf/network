#pragma once

namespace Network {
  class SystemReadParameters {
    private:
      size_t _bufferSize;
    public:
      SystemReadParameters(size_t buffer_size);
      size_t getBufferSize() const;
  };
};
