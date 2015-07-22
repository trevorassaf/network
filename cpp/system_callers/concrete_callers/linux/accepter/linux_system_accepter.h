#pragma once

#include "linux_namespace.h"
#include "../../../abstract_callers/accepter/system_accepter.h"

class Network::Linux::SystemAccepter :
    public Network::SystemAccepter {

  public:
    Network::SystemAcceptResults * accept(
        const Network::SystemAcceptParameters * system_accept_parameters
    ) const;
  
};
