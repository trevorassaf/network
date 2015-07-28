#pragma once

#include "linux_namespace.h"
#include "../../../abstract_callers/connecter/system_connecter.h"

class Network::Linux::SystemConnecter :
    public Network::SystemConnecter {

  public:
    Network::SystemConnectResults * connect(
        Network::SystemConnectParameters * system_connect_parameters
    ) const;

};
