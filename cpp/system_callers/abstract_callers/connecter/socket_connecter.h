#pragma once

#include "network_namespace.h"
#include "system_connecter.h"
#include "system_connect_parameters.h"
#include "system_connect_results.h"

class Network::SocketConnecter {

  private:
    const Network::SystemConnecter * _systemConnecter;
 
  protected:
    virtual Network::SystemConnectParameters *
        assembleSystemConnectParameters() const = 0;
    
    virtual void cacheSystemConnectResults(
        Network::SystemConnectResults * system_connect_results    
    ) const = 0;
  
  public:
    SocketConnecter(
        const Network::SystemConnecter * system_connecter    
    );

    void connect();
};
