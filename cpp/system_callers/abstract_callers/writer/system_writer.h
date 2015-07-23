#pragma once

#include "network_namespace.h"
#include "system_writer_parameters.h"
#include "system_writer_results.h"

class Network::SystemWriter {

  public:
    virtual const SystemWriterResults * write(
        const SystemWriterParameters * writer_params    
    ) const = 0;
};
