#pragma once

#include "network_namespace.h"
#include "system_open_parameters.h"
#include "system_open_results.h"

class Network::SystemOpener {
  
  public:
    virtual const SystemOpenResults * open(
        const SystemOpenParameters * open_params
    ) const = 0;
};
