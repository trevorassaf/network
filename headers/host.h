#pragma once

#include <unordered_map>
#include <functional>

#include "network.h"
#include "ipv4.h"
#include "ipv6.h"
#include "port.h"

class Network::Host {

    public:
      enum class AddressType {
        IPV4,
        IPV6
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

      Network::Ipv4 _ipv4;
      Network::Ipv6 _ipv6;
      Network::Port _port;

    public:
      /**
       * Host()
       * - Derives compatible ipv6 address from ipv4 address.
       * @param ipv4 : ipv4 address
       * @param port : port
       */
      Host(const Network::Ipv4 & ipv4, const Network::Port & port);
      
      /**
       * Host()
       * @param ipv6 : ipv6 address
       * @param port : port
       */
      Host(const Network::Ipv6 & ipv6, const Network::Port & port);

      /**
       * getIpv4()
       * @return ipv4 address
       * @throw runtime_error if no valid ipv4 address is available. Check first with
       *    Network::Ipv4::isIpv4()
       */
      const Network::Ipv4 & getIpv4() const;

      /**
       * getIpv6()
       * @return ipv6 address (always valid due to ipv4 -> ipv6 compatibility mapping)
       */
      const Network::Ipv6 & getIpv6() const;

      /**
       * getPort()
       * @return port
       * @throw std::runtime_error if port is unspecified. Check first with
       *    Network::Ipv4::hasPort()
       */
      const Network::Port & getPort() const;

      /**
       * getAddressFamily()
       * @return os code for this address family 
       */
      int getAddressFamily() const;

      /**
       * getAddressType()
       * @return address type of this host
       */
      AddressType getAddressType() const;

      /**
       * operator==()
       * @return true iff ip address and port are identical.
       */
      bool operator==(const Host & host);

      /**
       * operator!=()
       * @return true iff == operator fails.
       */
      bool operator!=(const Host & host);
};
