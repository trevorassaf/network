#pragma once

#include <unordered_map>
#include <functional>

#include "network.h"
#include "ipv4.h"
#include "ipv6.h"
#include "port.h"

#define CLIENT_DEFAULT_BACKLOG 10

class Network::ClientConfig {
    public:
      enum class AddressType {
        IPV4,
        IPV6,
        UNSPECIFIED
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

      bool _hasAddress;
      bool _hasPort;

      Network::Ipv4 _ipv4;
      Network::Ipv6 _ipv6;
      Network::Port _port;

      int _backlog;

    public:
      /**
       * ClientConfig()
       * - Defaults to localhost with unspecified ip with unspecified port.
       */
      ClientConfig();

      /**
       * hasAddress()
       * @return true iff address is set.
       */
      bool hasAddress() const;
      
      /**
       * hasPort()
       * @return true iff no port was indicated.
       */
      bool hasPort() const;

      /**
       * setIpv4()
       * @param ipv4 : ipv4 address
       * @return self
       */
      ClientConfig & setIpv4(const Network::Ipv4 & ipv4);

      /**
       * setIpv6()
       * @param ipv6 : ipv6 address
       * @return self
       */
      ClientConfig & setIpv6(const Network::Ipv6 & ipv6);
      
      /**
       * setPort()
       * @param port : port of host
       * @return self
       */
      ClientConfig & setPort(const Network::Port & port);

      /**
       * setBacklog()
       * @param backlog : number of allowed connections.
       *    Must be greater than 0.
       * @return self
       */
      ClientConfig & setBacklog(int backlog);

      /**
       * unsetAddress()
       * - Dissable ip address.
       * @return self
       */
      ClientConfig & unsetAddress();

      /**
       * unsetPort()
       * - Dissables port.
       * @return self
       */
      ClientConfig & unsetPort();

      /**
       * setIpv4()
       * - Configure address type for ipv4.
       */
      ClientConfig & setIpv4();
      
      /**
       * setIpv6()
       * - Configure address type for ipv6.
       * @return self
       */
      ClientConfig & setIpv6();

      /**
       * unsetAddressType()
       * - Configure address type for 'unspecified'
       * @return self
       */
      ClientConfig & setAddressUnspecified();

      /**
       * getAddressType()
       * @return address type for this host
       */
      AddressType getAddressType() const;

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
       * getBacklog()
       * @return the number of queued connections allowable.
       */
      int getBacklog() const;
};
