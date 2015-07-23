#pragma once

#include "network_namespace.h"
#include "system_write_parameters.h"
#include "system_write_results.h"

class Network::SystemWriter {

  public:
    virtual const SystemWriteResults * write(
        const SystemWriteParameters * writer_params    
    ) const = 0;
};
