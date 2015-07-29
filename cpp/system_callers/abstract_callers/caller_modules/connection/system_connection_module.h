#pragma once

#include <system_write_parameters>
#include <system_read_results>

namespace Network {

  class Network::SystemConnectionModule {

    public:
      virtual void write(
          const Network::SystemWriteParameters * writer_params    
      ) = 0;

      virtual const Network::SystemReadResults * read() = 0;
      
      virtual void close() = 0;
  };

}:
