#pragma once

#include "linux_namespace.h"
#include "../../../abstract_callers/accepter/socket_accepter.h"

#include <sys/types.h>
#include <sys/socket.h>

class Network::Linux::SocketAccepter :
    public Network::SocketAccepter {

  private:
    // Params
    unsigned int _socketDescriptor; 
    
    // Results
    struct sockaddr_storage _socketAddressStorage;
    socklen_t _socketAddressLength;

  protected:
    Network::SystemAcceptParameters *
        assembleSystemAcceptParameters() const;
    
    void cacheSystemAcceptResults(
        Network::SystemAcceptResults * system_accept_results    
    ) const;

  public:
    const struct sockaddr_storage & getSocketAddressStorage() const;
    
    socklen_t getSocketAddressLength() const;

    Network::Linux::SocketAccepter *
        setSocketDescriptor(unsigned int socket_descriptor);
};
