#pragma once

#include "network_namespace.h"

#include "cstdlib"

class Network::SystemWriteParameters {

  private:
    const void * _writeBuffer;
    size_t _writeBufferSize;

  public:
    SystemWriteParameters(
        const void * write_buffer,
        size_t write_buffer_size
    );
    const void * getWriteBuffer() const;
    size_t getWriteBufferSize() const;
};
