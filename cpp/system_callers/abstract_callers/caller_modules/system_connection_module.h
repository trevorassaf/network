#pragma once

#include "network_namespace.h"
#include "../writer/system_writer.h"
#include "../writer/system_write_parameters.h"
#include "../writer/system_write_results.h"
#include "../reader/system_reader.h"
#include "../reader/system_read_parameters.h"
#include "../reader/system_read_results.h"
#include "../closer/system_closer.h"
#include "../closer/system_close_parameters.h"
#include "../closer/system_close_results.h"

class Network::SystemConnectionModule {

  private:
    const Network::SystemWriter * _systemWriter;
    const Network::SystemReader * _systemReader;
    const Network::SystemCloser * _systemCloser;

  public:
    virtual const Network::SystemWriteResults * write(
        const Network::SystemWriteParameters * writer_params    
    ) = 0;

    virtual const Network::SystemReadResults * read(
        const Network::SystemReadParameters * read_params    
    ) = 0;
    
    virtual const Network::SystemCloseResults * close(
        const Network::SystemCloseParameters * writer_params    
    ) = 0;
};
