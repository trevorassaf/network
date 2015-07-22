#pragma once

#include "v6_namespace.h"
#include "socket_config.h"
#include "socket_builder.h"
#include "../../../socket.h"
#include "../../../socket_config.h"

#include <unordered_map>

class Network::Ip::V6::Socket :
    public Network::Socket,
    public Network::Ip::V6::SocketConfig {

  public:
    enum class Option {
      IPV6_ONLY
    };
    
    typedef std::unordered_map<Option, int, EnumClassKeyer> OsSocketOptionMap;
    typedef std::unordered_map<int, Option> ReverseOsSocketOptionMap;

    static const OsSocketOptionMap OPTION_MAP;
    static const ReverseOsSocketOptionMap REVERSE_OPTION_MAP;

    Network::Ip::V6::Socket * setIsIpv6Only(bool is_ipv6_only) override;
    Network::Ip::V6::Socket * enableIpv6Only() override;
    Network::Ip::V6::Socket * disableIpv6Only() override;

  protected:
    Network::SocketConfig::AddressFamily getAddressFamily() const override;
    void configureIpv6Socket(Network::Ip::V6::Socket * ipv6_socket) const;

  private:
    static const Level LEVEL;
};
