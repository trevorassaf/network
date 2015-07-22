#pragma once

#include "linux_namespace.h"
#include "../../../abstract_callers/binder/system_binder.h"

class Network::Linux::SystemBinder :
    public Network::SystemBinder {
  public:
    Network::SystemBindResults * bind(
        const Network::SystemBindParameters * system_bind_parameters
    ) const;
};
