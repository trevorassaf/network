#pragma once

#include <unordered_map>
#include <functional>

#include "network.h"
#include "ipv4.h"
#include "ipv6.h"
#include "port.h"

class Network::ServerConfig {

  friend class ServerConfigBuilder;

  public:
    
    enum class IpVersion {
      IPV4,
      IPV6,
      UNSPECIFIED
    };

    enum class AddressType {
      IP,
      DOMAIN
    };

  private:
    struct IpVersionKeyer {
      template <typename T>
      std::size_t operator()(const T & t) const {
        return static_cast<std::size_t>(t);
      }
    };
    
    typedef std::unordered_map<IpVersion, int, IpVersionKeyer> IpAddressFamilyMap; 
    typedef std::unordered_map<int, IpVersion> ReverseIpAddressFamilyMap; 
   
    static const IpAddressFamilyMap IP_ADDRESS_FAMILY_MAP;
    static const ReverseIpAddressFamilyMap REVERSE_IP_ADDRESS_FAMILY_MAP;

    const IpVersion _ipVersion;
    const AddressType _addressType;
    const bool _hasPort;
    const std::string _domain;
    const Network::Ipv4 _ipv4;
    const Network::Ipv6 _ipv6;
    const Network::Port _port;

    ServerConfig(
      IpVersion ip_version,
      AddressType address_type,
      bool has_port,
      const std::string & domain,
      const Network::Ipv4 & ipv4,
      const Network::Ipv6 & ipv6,
      const Network::Port & port
    );

  public:
    ServerConfig(const ServerConfig & server_config);

    IpVersion getIpVersion() const;
    AddressType getAddressType() const;
    bool hasPort() const;
    int getIpAddressFamily() const;
    const std::string & getDomain() const;
    const Network::Ipv4 & getIpv4() const;
    const Network::Ipv6 & getIpv6() const;
    const Network::Port & getPort() const;
    const std::string & getAddressStr() const;
};

class Network::ServerConfigBuilder {

    private:
      Network::ServerConfig::IpVersion _ipVersion;      
      Network::ServerConfig::AddressType _addressType;
      
      bool _hasAddress;
      bool _hasPort;

      Network::Ipv4 _ipv4;
      Network::Ipv6 _ipv6;
      Network::Port _port;

      std::string _domain;

      void validateStateOrThrow() const;

    public:
      /**
       * ServerConfigBuilder()
       * - Defaults to localhost with unspecified ip with unspecified port.
       */
      ServerConfigBuilder();

      /**
       * setIpv4()
       * @param ipv4 : ipv4 address
       * @return self
       */
      ServerConfigBuilder & setIpv4(const Network::Ipv4 & ipv4);

      /**
       * setIpv6()
       * @param ipv6 : ipv6 address
       * @return self
       */
      ServerConfigBuilder & setIpv6(const Network::Ipv6 & ipv6);
      
      /**
       * setPort()
       * @param port : port of host
       * @return self
       */
      ServerConfigBuilder & setPort(const Network::Port & port);
      
      /**
       * setDomain()
       * @param domain : domain name of the remote
       * @return self
       */
      ServerConfigBuilder & setDomain(const std::string & domain);

      /**
       * enableIpv4()
       * - Set ip type to ipv4
       * @return self
       */
      ServerConfigBuilder & enableIpv4();
      
      /**
       * enableIpv6()
       * - Set ip type to ipv6
       * @return self
       */
      ServerConfigBuilder & enableIpv6();
      
      const Network::ServerConfig build() const;
      const Network::ServerConfig * buildNew() const;

};
