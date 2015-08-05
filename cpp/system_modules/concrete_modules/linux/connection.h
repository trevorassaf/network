#pragma once

#include <ip/host.h>
#include <ip/address_family.h>

#include <system_modules/abstract_modules/connection/system_connection_module.h>

#include <sys/types.h>
#include <sys/socket.h>

namespace Network {
  namespace Linux {  
    class Connection : public Network::SystemConnectionModule {
      
      private:
        const int _socketDescriptor;
        const Network::Ip::Host _remoteHost;
        const Network::Ip::Host _localHost;

        Network::Ip::Host generateRemoteHost(int socket_descriptor) const;
        Network::Ip::Host generateLocalHost(int socket_descriptor) const;
        Network::Ip::Host deriveHost(
            const sockaddr_storage & socket_storage
        ) const;

      public:
        Connection(int socket_descriptor);

        const Network::Ip::Host & getRemoteHost() const override;
        
        const Network::Ip::Host & getLocalHost() const override;
        
        void write(
            const Network::SystemWriteParameters & write_params
        ) const override;
        
        const Network::SystemReadResults read(
            const Network::SystemReadParameters & read_parameters    
        ) const override;

        void close() override;
    };
  };
};
