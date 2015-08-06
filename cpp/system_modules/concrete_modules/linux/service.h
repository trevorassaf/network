#pragma once

#include <system_modules/abstract_modules/service/system_service_module.h>
#include <ip/address_family.h>
#include <ip/socket_type.h>
#include <ip/host.h>
#include <ip/address.h>

#include <unordered_map>
#include <vector>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/ip.h>

namespace Network {
  namespace Linux {
    class Service : public Network::SystemServiceModule {
      
      private:
        typedef std::unordered_map<int, Network::Ip::AddressFamily> OsAddressFamilyMap;
        static const OsAddressFamilyMap OS_ADDRESS_FAMILY_MAP;
        static Network::Ip::AddressFamily translateOsCodeToAddressFamily(int os_code);
       
        typedef std::unordered_map<int, Network::Ip::SocketType> OsSocketTypeMap;
        static const OsSocketTypeMap OS_SOCKET_TYPE_MAP;
        static Network::Ip::SocketType translateOsCodeToSocketType(int os_code);

        const Network::Ip::Host generateIpv4Host(
            const sockaddr_in & ipv4_address
        ) const;
        
        const Network::Ip::Host generateIpv6Host(
            const sockaddr_in6 & ipv6_address
        ) const;

        const Network::Ip::Host generateLocalHost() const;

        const unsigned int _socketDescriptor;

        const Network::SystemServiceModule::ListeningHosts _listeningHosts;

        bool _isOpen;

      public:
        Service(
            unsigned int socket_descriptor,
            const Network::SystemServiceModule::ListeningHosts & listening_hosts
        );
        
        Network::SystemAcceptResults accept() override;
        
        const Network::SystemServiceModule::ListeningHosts & getListeningHosts() const override;

        void close() override;

        ~Service() override;
    };
  };
};
