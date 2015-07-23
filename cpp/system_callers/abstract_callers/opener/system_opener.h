#pragma once

#include "network_namespace.h"
#include "system_open_parameters.h"
#include "system_open_results.h"

class Network::SystemOpener {
  
  public:
    virtual const Network::SystemOpenResults * open(
        const Network::SystemOpenParameters * open_params
    ) const = 0;
};
