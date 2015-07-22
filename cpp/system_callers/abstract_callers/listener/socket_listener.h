#pragma once

#include "network_namespace.h"
#include "system_listener.h"
#include "system_listen_parameters.h"
#include "system_listen_results.h"

class Network::SocketListener {

  private:
    const Network::SystemListener * _systemListener;
    bool _hasResults;
 
  protected:
    virtual const Network::SystemListenParameters *
        assembleSystemListenParameters() const = 0;
    
    virtual void cacheSystemListenResults(
        const Network::SystemListenResults * system_listen_results    
    ) const = 0;
  
  public:
    SocketListener(
        const Network::SystemListener * system_listener    
    );

    void listen();
    
    bool hasResults() const;
};
