#pragma once

#include "network_namespace.h"

#include "cstdlib"

class Network::SystemReadResults {

  private:
    const void * _readBuffer;
    size_t _readBufferSize;

  public:
    SystemReadResults(
        const void * read_buffer,
        size_t read_buffer_size
    );
    const void * getReadBuffer() const;
    size_t getReadBufferSize() const;
};
