#pragma once

#include "linux_namespace.h"
#include "../../../abstract_callers/listener/system_listener.h"

class Network::Linux::SystemListener :
    public Network::SystemListener {
  public:
    Network::SystemListenResults * listen(
        Network::SystemListenParameters system_listen_parameters
    ) const;
};
