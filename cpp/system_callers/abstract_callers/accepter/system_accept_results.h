#pragma once

#include "network_namespace.h"

#include <sys/types.h>
#include <sys/socket.h>

class Network::SystemAcceptResults {

  private:
    const struct sockaddr_storage _socketAddressStorage;
    const socklen_t _socketAddressStorageBytes;

  public:
    SystemAcceptResults(
        struct sockaddr_storage & socket_address_storage,
        socklen_t socket_address_storage_bytes
    );

    const struct sockaddr_storage & getSocketAddressStorage() const;
    socklen_t getSocketAddressStorageBytes() const;
};
