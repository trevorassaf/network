#pragma once

#include "linux_namespace.h"
#include "../../../abstract_callers/listener/socket_listener.h"

class Network::Linux::SocketListener :
    public Network::SocketListener {

  private:
    unsigned int _socketDescriptor;
    unsigned int _backlogSize; 

  protected:
    Network::SystemListenParameters *
        assembleSystemListenParameters() const override;
    
    void cacheSystemListenResults(
        Network::SystemListenResults * system_listen_results    
    ) const override;

  public:
    SocketListener(
        const Network::SystemListener * system_listener    
    );
    
    SocketListener * setBacklogSize(unsigned int backlog_size);
};
