#pragma once

#include "network_namespace.h"
#include "../opener/system_opener.h"
#include "../opener/system_open_parameters.h"
#include "../opener/system_open_results.h"
#include "../binder/system_binder.h"
#include "../binder/system_bind_parameters.h"
#include "../binder/system_bind_results.h"
#include "../listener/system_listener.h"
#include "../listener/system_listen_parameters.h"
#include "../listener/system_listen_results.h"
#include "../closer/system_closer.h"
#include "../closer/system_close_parameters.h"
#include "../closer/system_close_results.h"

class Network::SystemListenerModule {

  private:
    const Network::SystemOpener * _systemOpener;
    const Network::SystemBinder * _systemBinder;
    const Network::SystemListener * _systemListener;
    const Network::SystemCloser * _systemCloser;

  public:
    virtual const Network::SystemOpenResults * open(
        const Network::SystemOpenParameters * open_params    
    ) = 0;

    virtual const Network::SystemBindResults * bind(
        const Network::SystemBindParameters * bind_params    
    ) = 0;

    virtual const Network::SystemListenResults * listen(
        const Network::SystemListenParameters * listen_params    
    ) = 0;
    
    virtual const Network::SystemCloseResults * close(
        const Network::SystemCloseParameters * writer_params    
    ) = 0;
};
