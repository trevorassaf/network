#pragma once

#include "network_namespace.h"
#include "system_listen_parameters.h"
#include "system_listen_results.h"

class Network::SystemListener {
  public:
    virtual Network::SystemListenResults * listen(
        Network::SystemListenParameters system_listen_parameters
    ) const = 0;
};
