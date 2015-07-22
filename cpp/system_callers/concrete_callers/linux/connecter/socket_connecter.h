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
    Network::SystemConnectParameters *
        assembleSystemConnectParameters() const;
    
    void cacheSystemConnectResults(
        Network::SystemConnectResults * system_connect_results    
    ) const;

    virtual Network::Linux::SocketConnecter *
        setSocketAddressStorage(
            const struct sockaddr_storage & socket_address
        ) = 0;

    virtual Network::Linux::SocketConnecter *
        setSocketAddressBytes(
            socklen_t socket_address_bytes
        ) = 0;

  public:
    Network::Linux::SocketConnecter *
        setSocketDescriptor(unsigned int socket_descriptor);
};
