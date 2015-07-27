#pragma once

#include "network_namespace.h"
#include "../opener/system_opener.h"
#include "../opener/system_open_parameters.h"
#include "../opener/system_open_results.h"
#include "../binder/system_binder.h"
#include "../binder/system_bind_parameters.h"
#include "../binder/system_bind_results.h"
#include "../connecter/system_connecter.h"
#include "../connecter/system_connect_parameters.h"
#include "../connecter/system_connect_results.h"
#include "../closer/system_closer.h"
#include "../closer/system_close_parameters.h"
#include "../closer/system_close_results.h"

class Network::SystemConnecterModule {

  public:
    virtual const Network::SystemOpenResults * open(
        const Network::SystemOpenParameters * open_params    
    ) = 0;

    virtual Network::SystemOpenAndBindResults * openAndBind(
        const Network::SystemOpenAndBindParameters * system_open_and_bind_parameters
    ) = 0;
    
    virtual Network::SystemConnectResults * connect(
        const Network::SystemConnectParameters * system_connect_parameters
    ) = 0;
    
    virtual Network::SystemCloseResults * close(
        const Network::SystemCloseParameters * system_connect_parameters
    ) = 0;
};
