#pragma once

#include "network_namespace.h"
#include "../accepter/system_accepter.h"
#include "../accepter/system_accept_parameters.h"
#include "../accepter/system_accept_results.h"
#include "../closer/system_closer.h"
#include "../closer/system_close_parameters.h"
#include "../closer/system_close_results.h"

class Network::SystemServiceModule {

  public:
    virtual const Network::SystemAcceptResults * accept(
        const Network::SystemAcceptParameters * accept_params    
    ) = 0;
    
    virtual const Network::SystemCloseResults * close(
        const Network::SystemCloseParameters * writer_params    
    ) = 0;
};
