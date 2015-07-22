#pragma once

#include "linux_namespace.h"
#include "../../../abstract_callers/connecter/socket_connecter.h"

#include <sys/types.h>
#include <sys/socket.h>

class Network::Linux::SocketConnecter :
    public Network::SocketConnecter {
  
  private:
    unsigned int _socketDescriptor;
    struct sockaddr_storage _socketAddressStorage; 
    socklen_t _socketAddressBytes;

  protected:
    const Network::SystemConnectParameters *
        assembleSystemConnectParameters() const override;
    
    void cacheSystemConnectResults(
        const Network::SystemConnectResults * system_connect_results    
    ) const override;

  public:
    Network::Linux::SocketConnecter *
        setSocketAddressStorage(
            const struct sockaddr_storage & socket_address
        );

    Network::Linux::SocketConnecter *
        setSocketAddressBytes(
            socklen_t socket_address_bytes
        );

    Network::Linux::SocketConnecter *
        setSocketDescriptor(unsigned int socket_descriptor);
};
