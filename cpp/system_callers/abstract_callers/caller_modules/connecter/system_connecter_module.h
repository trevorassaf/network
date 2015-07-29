#pragma once

#include <network_namespace>

class Network::SystemConnecterModule {

  public:
    virtual const Network::SystemConnectResults * connect(
        const Network::SystemConnectParameters * system_connect_parameters    
    ) = 0;

    virtual const Network::SystemConnectWithBindResults * connect(
        const Network::SystemConnectWithBindParameters * system_connect_parameters    
    ) = 0;
};
