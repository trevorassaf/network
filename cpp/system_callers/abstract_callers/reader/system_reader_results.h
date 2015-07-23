#pragma once

#include "network_namespace.h"
#include <sys/types.h>
#include <sys/socket.h>

class Network::SystemReaderResults {

  private:
    const void * _dataBuffer;
    socklen_t _dataBufferSize;

  public:
    SystemReaderResults(
        const void * _dataBuffer,
        socklen_t _dataBufferSize
    );

    const void * getDataBuffer() const;
    socklen_t getDataBufferSize() const;
};
