#pragma once

#include <system_modules/abstract_modules/connecter/system_connecter_module.h>
#include <system_modules/abstract_modules/connecter/system_connect_parameters.h>
#include <system_modules/abstract_modules/connecter/system_connect_results.h>

#include <ip/host.h>

#include <sys/types.h>
#include <sys/socket.h>

namespace Network {
  namespace Linux {  
    class Connecter : public Network::SystemConnecterModule {

      private:
        void bindLocalHostConfig(
            int socket_descriptor,
            const Network::Ip::ConnecterHostConfig & connecter_host_config
        );

        const Network::Ip::Host getLocalHost(int socket_descriptor) const;

        const Network::Ip::Host getRemoteHost(int socket_descriptor) const;

        const Network::Ip::Host deriveHost(
            const sockaddr_storage & socket_storage
        ) const;

      public:
        const Network::SystemConnectResults * connect(
            const Network::SystemConnectParameters & system_connect_parameters    
        );
    };
  };
};
