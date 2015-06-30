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
      Network::Ipv4 * _ipv4;
      Network::Ipv6 * _ipv6;
      Network::Port * _port;

    public:
      HostBuilder();
      HostBuilder * setIpv4(const Network::Ipv4 & ipv4);
      HostBuilder * setIpv6(const Network::Ipv6 & ipv6);
      HostBuilder * setPort(const Network::Port & port);
      const Network::Host build();

};

class Network::Host {

    private:
      bool _isIpv4;
      bool _isPortSpecified;
      
      Network::Ipv4 * _ipv4;
      Network::Ipv6 * _ipv6;
      Network::Port * _port;

      Host(
          const Network::Ipv4 * ipv4,
          const Network::Ipv6 * ipv6,
          const Network::Port * port
      );

    public:
      Host(const Host & host);
      ~Host();
      bool isIpv4() const;
      bool isPortSpecified() const;
      const Network::Ipv4 * getIpv4() const;
      const Network::Ipv6 * getIpv6() const;
      const Network::Port * getPort() const;
};
