#pragma once

#include <system_modules/abstract_modules/connection/system_read_parameters.h>
#include <system_modules/abstract_modules/connection/system_read_results.h>
#include <system_modules/abstract_modules/connection/system_write_parameters.h>

namespace Network {

  class SystemConnectionModule {

    public:
      virtual void write(
          const Network::SystemWriteParameters * write_params    
      ) = 0;
  
      SystemConnectionModule(const SystemConnectionModule & module) = delete;
      SystemConnectionModule & operator=(const SystemConnectionModule & module) = delete;

      virtual ~SystemConnectionModule();

      virtual const Network::SystemReadResults * read(
          const Network::SystemReadParameters * read_parameters
      ) = 0;
      
      virtual void close() = 0;
  };
};
