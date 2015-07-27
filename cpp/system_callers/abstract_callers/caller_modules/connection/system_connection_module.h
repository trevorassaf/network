#pragma once

#include "network_namespace.h"
#include "system_write_parameters.h"
#include "system_read_results.h"

class Network::SystemConnectionModule {

  public:
    virtual void write(
        const Network::SystemWriteParameters * writer_params    
    ) = 0;

    virtual const Network::SystemReadResults * read() = 0;
    
    virtual void close() = 0;
};
