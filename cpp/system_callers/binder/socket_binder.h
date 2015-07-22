#pragma once

#include "network_namespace.h"
#include "system_binder.h"
#include "system_bind_parameters.h"
#include "system_bind_results.h"

class Network::SocketBinder {

  private:
    const Network::SystemBinder * _systemBinder;
 
  protected:
    virtual Network::SystemBindParameters *
        assembleSystemBindParameters() const = 0;
    
    virtual void cacheSystemBindResults(
        Network::SystemBindResults * system_bind_results    
    ) const = 0;
  
  public:
    SocketBinder(
        const Network::SystemBinder * system_binder    
    );
    void bind();
};
