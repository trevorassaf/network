#pragma once

#include "network_namespace.h"

#include <sys/types.h>
#include <sys/socket.h>

class Network::SystemAcceptParameters {

  private:
    const int _socketDescriptor;

  public:
    SystemAcceptParameters(
        int socket_descriptor
    );

    int getSocketDescriptor() const;
};
