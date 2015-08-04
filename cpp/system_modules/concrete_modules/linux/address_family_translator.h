#pragma once

#include <ip/address_family.h>
#include <util/enum_keyer.h>

#include <unordered_map>

namespace Network {
  namespace Linux {
    class AddressFamilyTranslator {
      
      private:
        typedef std::unordered_map<Network::Ip::AddressFamily, int, EnumClassKeyer> AddressFamilyToOsCodeMap;
        static const AddressFamilyToOsCodeMap ADDRESS_FAMILY_TO_OS_CODE_MAP;

        typedef std::unordered_map<int, Network::Ip::AddressFamily> OsCodeToAddressFamilyMap; 
        static const OsCodeToAddressFamilyMap OS_CODE_TO_ADDRESS_FAMILY_MAP;

      public:
        int translateToOsCode(Network::Ip::AddressFamily address_family) const;
        Network::Ip::AddressFamily translateFromOsCode(int os_code) const;
    };
  };
};
