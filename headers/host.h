#pragma once

#include "network.h"
#include "ipv4.h"
#include "ipv6.h"
#include "port.h"

class Network::Host {

    private:
      bool _isIpv4;
      bool _hasPort;
      const Network::Ipv4 _ipv4;
      const Network::Ipv6 _ipv6;
      const Network::Port _port;

    public:
      /**
       * Host()
       * - Defaults to localhost on ipv4 with unspecified port.
       */
      Host();

      /**
       * Host()
       * - Derives compatible ipv6 address from ipv4 address.
       * - Portless state
       * @param ipv4 : ipv4 address
       */
      Host(const Network::Ipv4 & ipv4);
      
      /**
       * Host()
       * - Portless state.
       * @param ipv6 : ipv6 address
       */
      Host(const Network::Ipv6 & ipv6);

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
       * isIpv4()
       * @return true iff the ipv4 address is enabled. All ipv4 addresses can be translated
       *    to ipv6, but not the other way around.
       */
      bool isIpv4() const;

      /**
       * hasPort()
       * @return true iff no port was indicated.
       */
      bool hasPort() const;

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
       * operator==()
       * @return true iff flags are equal and active fields are identical. By "active", we mean
       *    the fields indicated by the flags.
       */
      bool operator==(const Host & host);

      /**
       * operator!=()
       * @return true iff == operator fails.
       */
      bool operator!=(const Host & host);
};
