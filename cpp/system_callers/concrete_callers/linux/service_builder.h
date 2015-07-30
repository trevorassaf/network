#pragma once

#include <system_callers/abstract_callers/caller_modules/service_builder/system_service_builder_module>
#include <ip/address_family>
#include <ip/socket_type>

#include <unordered_map>

namespace Network {
  namespace Linux {
    class ServiceBuilder : public Network::SystemServiceModule {
     private:
        // Address family functions
        typedef std::unordered_map<AddressFamily, int> AddressFamilyMap;
        static const AddressFamilyMap ADDRESS_FAMILY_MAP;
        static int translateAddressFamilyToOsCode(Network::Ip::AddressFamily address_family);

        // Socket type functions
        typedef std::unordered_map<SocketType, int> SocketTypeMap;
        static const SocketTypeMap SOCKET_TYPE_MAP;
        static int translateSocketTypeToOsCode(Network::Ip::SocketType socket_type);

      public:
        const Network::SystemListenResults * listen(
            const Network::SystemListenParameters * listen_params    
        ) override; 
    };
  };
};
