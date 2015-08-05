#pragma once

#include <ip/host.h>

#include <system_modules/abstract_modules/connection/system_connection_module.h>

namespace Network {
  namespace Linux {  
    class Connection : public Network::SystemConnectionModule {
      
      private:
        int _socketDescriptor;
        const Network::Ip::Host _remoteHost;
        const Network::Ip::Host _localHost;

      public:
        Connection(
            int socket_descriptor,
            const Network::Ip::Host & remote_host,
            const Network::Ip::Host & local_host
        );

        const Network::Ip::Host & getRemoteHost() const override;
        
        const Network::Ip::Host & getLocalHost() const override;
        
        void write(
            const Network::SystemWriteParameters * write_params
        ) const override;
        
        const Network::SystemReadResults * read(
            const Network::SystemReadParameters * read_parameters    
        ) const override;

        void close() override;
    };
  };
};
