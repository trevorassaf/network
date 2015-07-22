#pragma once

#include "network_namespace.h"
#include "system_close_parameters.h"
#include "system_close_results.h"

class Network::SystemCloser {
  public:
    virtual Network::SystemCloseResults * close(
        const Network::SystemCloseParameters * system_close_parameters
    ) const = 0;
};

