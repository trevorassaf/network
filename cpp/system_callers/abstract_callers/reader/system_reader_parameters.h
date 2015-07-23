#pragma once

#include "network_namespace.h"

#include <sys/types.h>
#include <sys/socket.h>

class Network::SystemReaderParameters {

  private:
    int _socketDescriptor;

  public:
    SystemReaderParameters(
        int socket_descriptor
    );

    int getSocketDescriptor() const;
};
