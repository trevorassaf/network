#pragma once

#include "network_namespace.h"
#include "system_bind_parameters.h"
#include "system_bind_results.h"

class Network::SystemBinder {
  public:
    Network::SystemBindResults * bind(
        Network::SystemBindParameters system_bind_parameters
    ) const;
};

