#pragma once

#include "network_namespace.h"
#include "system_accept_parameters.h"
#include "system_accept_results.h"

class Network::SystemAccepter {
  public:
    Network::SystemAcceptResults * accept(
        Network::SystemAcceptParameters system_accept_parameters
    ) const;
};

