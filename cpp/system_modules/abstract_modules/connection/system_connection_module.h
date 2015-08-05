#pragma once

#include <ip/host.h>

#include <system_modules/abstract_modules/connection/system_read_parameters.h>
#include <system_modules/abstract_modules/connection/system_read_results.h>
#include <system_modules/abstract_modules/connection/system_write_parameters.h>

namespace Network {

  class SystemConnectionModule {

    public:
      SystemConnectionModule(const SystemConnectionModule & module) = delete;
      SystemConnectionModule & operator=(const SystemConnectionModule & module) = delete;

      virtual ~SystemConnectionModule() = 0;
      
      virtual const Network::Ip::Host & getRemoteHost() const = 0;

      virtual const Network::Ip::Host & getLocalHost() const = 0;

      virtual void write(
          const Network::SystemWriteParameters * write_params    
      ) const = 0;

      virtual const Network::SystemReadResults * read(
          const Network::SystemReadParameters * read_parameters
      ) const = 0;
      
      virtual void close() = 0;
  };
};
