#pragma once

#include "linux_namespace.h"
#include "../../../abstract_callers/opener/socket_opener.h"

class Network::Linux::SocketOpener :
    public Network::SocketOpener {

  private:
    int _socketDiscriptor;

  protected:
    const Network::SystemOpenParameters *
        assembleSystemOpenParameters() const override;
    
    void cacheSystemOpenResults(
        Network::SystemOpenResults * system_open_results    
    ) const override;

  public:
    int getSocketDiscriptor() const;
};
