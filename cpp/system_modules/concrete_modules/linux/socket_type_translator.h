#pragma once

#include <ip/socket_type.h>
#include <util/enum_keyer.h>

#include <unordered_map>

namespace Network {
  namespace Linux {
    class SocketTypeTranslator {
      
      private:
        typedef std::unordered_map<Network::Ip::SocketType, int, EnumClassKeyer> SocketTypeToOsCodeMap;
        static const SocketTypeToOsCodeMap SOCKET_TYPE_TO_OS_CODE_MAP;

        typedef std::unordered_map<int, Network::Ip::SocketType> OsCodeToSocketTypeMap; 
        static const OsCodeToSocketTypeMap OS_CODE_TO_SOCKET_TYPE_MAP;

      public:
        int translateToOsCode(Network::Ip::SocketType address_family) const;
        Network::Ip::SocketType translateFromOsCode(int os_code) const;

    };
  };
};
