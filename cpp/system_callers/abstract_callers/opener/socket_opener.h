#pragma once

#include "network_namespace.h"
#include "system_opener.h"

class Network::SocketOpener {
  private:
    const Network::SystemOpener * _systemOpener;
    bool _hasResults;
  
  protected:
    virtual const SystemOpenParameters *
        assembleSystemOpenParameters() const = 0;

    virtual void cacheSystemOpenResults(
        const Network::SystemOpenResults * system_open_results    
    ) const = 0;
  
  public:
    SocketOpener(
        const Network::SystemOpener * system_opener    
    );
    
    void open();
    
    bool hasResults() const;
};
