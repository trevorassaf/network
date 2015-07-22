#pragma once

#include "network_namespace.h"
#include "system_opener.h"

class Network::SocketOpener {
  private:
    const Network::SystemOpener * _systemOpener;
  
  protected:
    virtual const SystemOpenParameters *
        assembleSystemOpenParameters() const = 0;

    virtual void cacheSystemOpenResults(
        Network::SystemOpenResults * system_open_results    
    ) const = 0;
  
  public:
    SocketOpener(
        const Network::SystemOpener * system_opener    
    );
    void open();
};
