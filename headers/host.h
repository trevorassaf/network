#pragma once

#include <unordered_map>
#include <functional>

#include "network_namespace.h"

class Network::Host {

    public:
      enum class AddressType {
        IPV4,
        IPV6,
        UNIX,
      };

    private:
      struct AddressTypeKeyer {
        template <typename T>
        std::size_t operator()(const T & t) const {
          return static_cast<std::size_t>(t);
        }
      };

      AddressType _addressType;

      typedef std::unordered_map<AddressType, int, AddressTypeKeyer> AddressFamilyMap; 
      typedef std::unordered_map<int, AddressType> ReverseAddressFamilyMap; 
     
      static const AddressFamilyMap ADDRESS_FAMILY_MAP;
      static const ReverseAddressFamilyMap REVERSE_ADDRESS_FAMILY_MAP;

    public:
      virtual AddressType getAddressType() const = 0;
};
