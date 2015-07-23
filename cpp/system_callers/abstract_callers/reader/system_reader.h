#pragma once

#include "network_namespace.h"
#include "system_read_parameters.h"
#include "system_read_results.h"

class Network::SystemReader {

  public:
    virtual const SystemReadResults * read(
        const SystemReadParameters * reader_params    
    ) const = 0;
};
