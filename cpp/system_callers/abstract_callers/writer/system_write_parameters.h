#pragma once

#include "network_namespace.h"

#include <sys/types.h>
#include <sys/socket.h>

class Network::SystemWriteParameters {

  private:
    int _socketDescriptor;
    const void * _dataBuffer;
    socklen_t _dataBufferSize;

  public:
    SystemWriteParameters(
        int socket_descriptor,
        const void * data_buffer,
        socklen_t data_buffer_size
    );

    int getSocketDescriptor() const;
    const void * getDataBuffer() const;
    socklen_t getDataBufferSize() const;
};
