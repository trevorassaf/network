#pragma once

#include "network_namespace.h"
#include "system_closer.h"
#include "system_close_parameters.h"
#include "system_close_results.h"

class Network::SocketCloser {

  private:
    const Network::SystemCloser * _systemCloser;
 
  protected:
    virtual Network::SystemCloseParameters *
        assembleSystemCloseParameters() const = 0;
    
    virtual void cacheSystemCloseResults(
        Network::SystemCloseResults * system_close_results    
    ) const = 0;
  
  public:
    SocketCloser(
        const Network::SystemCloser * system_closer    
    );
    void close();
};
