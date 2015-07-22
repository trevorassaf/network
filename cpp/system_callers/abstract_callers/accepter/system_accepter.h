#pragma once

#include "network_namespace.h"
#include "system_accept_parameters.h"
#include "system_accept_results.h"

class Network::SystemAccepter {

  public:
    virtual Network::SystemAcceptResults * accept(
        const Network::SystemAcceptParameters * system_accept_parameters
    ) const = 0;

};

