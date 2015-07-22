#pragma once

#include "network_namespace.h"
#include "system_close_parameters.h"
#include "system_close_results.h"

class Network::SystemCloser {
  public:
    Network::SystemCloseResults * close(
        Network::SystemCloseParameters system_close_parameters
    ) const;
};

