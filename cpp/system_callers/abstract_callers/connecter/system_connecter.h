#pragma once

#include "network_namespace.h"
#include "system_connect_parameters.h"
#include "system_connect_results.h"

class Network::SystemConnecter {
  public:
    Network::SystemConnectResults * connect(
        Network::SystemConnectParameters & system_connect_parameters
    ) const;
};
