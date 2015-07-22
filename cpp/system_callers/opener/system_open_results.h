#pragma once

#include "network_namespace.h"

class Network::SystemOpenResults {
  private:
    int _socketDescriptor;
  public:
    SystemOpenResults(int socket_descriptor);
    int getSocketDescriptor() const;
};
