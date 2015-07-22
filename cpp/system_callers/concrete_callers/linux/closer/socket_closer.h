#pragma once

#include "linux_namespace.h"
#include "../../../abstract_callers/closer/socket_closer.h"

class Network::Linux::SocketCloser :
    public Network::SocketCloser {

  private:
    unsigned int _socketDescriptor;

  protected:
    const Network::SystemCloseParameters *
        assembleSystemCloseParameters() const override;
    
    void cacheSystemCloseResults(
        const Network::SystemCloseResults * system_close_results    
    ) const override;

  public:
    SocketCloser(
        const Network::SystemCloser * system_closer    
    );

    SocketCloser * setSocketDescriptor(unsigned int socket_descriptor);
};
