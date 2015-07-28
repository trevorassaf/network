#pragma once

#include "linux_namespace.h"
#include "../../../abstract_callers/opener/system_opener.h"

class Network::Linux::SystemOpener :
    public Network::SystemOpener {

  public:
    virtual Network::SystemOpenResults open(
        const Network::SystemOpenParameters * open_params
    ) const = 0;
};
