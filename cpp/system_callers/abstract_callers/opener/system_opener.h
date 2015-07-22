#pragma once

#include "network_namespace.h"
#include "system_open_parameters.h"
#include "system_open_results.h"

class Network::SystemOpener {
  public:
    SystemOpenResults open(const SystemOpenParameters * open_params) const;
};
