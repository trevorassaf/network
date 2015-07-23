#pragma once

#include "network_namespace.h"

#include <sys/types.h>
#include <sys/socket.h>

class Network::SystemReadParameters {

  private:
    int _socketDescriptor;

  public:
    SystemReadParameters(
        int socket_descriptor
    );

    int getSocketDescriptor() const;
};
