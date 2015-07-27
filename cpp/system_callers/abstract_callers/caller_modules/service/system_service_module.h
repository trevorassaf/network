#pragma once

#include "network_namespace.h"

#include "system_accept_results.h"

class Network::SystemServiceModule {

  public:
    virtual const Network::SystemAcceptResults * accept() = 0;
    
    virtual void close() = 0;
};
