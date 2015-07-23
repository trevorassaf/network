#pragma once

#include "network_namespace.h"
#include "system_reader_parameters.h"
#include "system_reader_results.h"

class Network::SystemReader {

  public:
    virtual const SystemReaderResults * read(
        const SystemReaderParameters * reader_params    
    ) const = 0;
};
