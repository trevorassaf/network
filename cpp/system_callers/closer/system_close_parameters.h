#pragma once

#include "network_namespace.h"

#include <sys/types.h>
#include <sys/socket.h>

class Network::SystemCloseParameters {

  private:
    const int _socketDescriptor;
    const struct sockaddr_storage _socketAddressStorage;
    const socklen_t _socketAddressStorageLength;

  public:
    SystemCloseParameters(
        int socket_descriptor,
        const struct sockaddr_storage & socket_address_storage,
        socklen_t socket_length
    );

    int getSocketDescriptor() const;
    const struct sockaddr_storage & getSocketAddressStorage() const;
    socklen_t getSocketAddressStorageLength() const;
};
