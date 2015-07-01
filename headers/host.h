#pragma once

#include "network.h"
#include "ipv4.h"
#include "ipv6.h"
#include "port.h"

class Network::HostBuilder {

    private:
      
      friend class Network::Host;

      bool _isIpv4;
      bool _isPortSpecified;
      bool _isAddressSet;
      const Network::Ipv4 * _ipv4;
      const Network::Ipv6 * _ipv6;
      const Network::Port * _port;

    public:
      /**
       * HostBuilder()
       *
       */
      HostBuilder();
      HostBuilder * setIpv4(const Network::Ipv4 * ipv4);
      HostBuilder * setIpv6(const Network::Ipv6 * ipv6);
      HostBuilder * setPort(const Network::Port * port);
      const Network::Host build();

};

class Network::Host {

    private:
      bool _isIpv4;
      bool _isPortSpecified;
      
      const Network::Ipv4 * _ipv4;
      const Network::Ipv6 * _ipv6;
      const Network::Port * _port;

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
      Host(const Network::Ipv4 & ipv6);

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
      Host(const Network::Ipv4 & ipv6, const Network::Port & port);


    public:
      /**
       * Host()
       * @param host : peer host to deep-clone
       */
      Host(const Host & host);

      /**
       * ~Host()
       * - Frees ipv4, ipv6, port
       */
      ~Host();

      /**
       * isIpv4()
       * @return true iff the ipv4 address is enabled. All ipv4 addresses can be translated
       *    to ipv6, but not the other way around.
       */
      bool isIpv4() const;

      /**
       * isPortSpecified()
       * @return true iff no port was indicated.
       */
      bool isPortSpecified() const;

      /**
       * getIpv4()
       * @return ipv4 address
       * @throw runtime_error if no valid ipv4 address is available. Check first with
       *    Network::Ipv4::isIpv4()
       */
      const Network::Ipv4 * getIpv4() const;

      /**
       * getIpv6()
       * @return ipv6 address (always valid due to ipv4 -> ipv6 compatibility mapping)
       */
      const Network::Ipv6 * getIpv6() const;

      /**
       * getPort()
       * @return port
       * @throw std::runtime_error if port is unspecified. Check first with
       *    Network::Ipv4::isPortSpecified()
       */
      const Network::Port * getPort() const;
};
