#pragma once

#include "linux_namespace.h"
#include "../../../abstract_callers/closer/system_closer.h"

class Network::Linux::SystemCloser :
    public Network::SystemCloser {

  public:
    Network::SystemCloseResults * close(
        const Network::SystemCloseParameters * system_close_params
    ) const override;
};
