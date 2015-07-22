#pragma once

#include "network_namespace.h"
#include "system_accepter.h"
#include "system_accept_parameters.h"
#include "system_accept_results.h"

class Network::SocketAccepter {

  private:
    const Network::SystemAccepter * _systemAccepter;
    bool _hasResults;
 
  protected:
    virtual const Network::SystemAcceptParameters *
        assembleSystemAcceptParameters() const = 0;
    
    virtual void cacheSystemAcceptResults(
        const Network::SystemAcceptResults * system_accept_results    
    ) const = 0;
  
  public:
    SocketAccepter(
        const Network::SystemAccepter * system_accepter    
    );

    void accept();

    bool hasResults() const;
};
