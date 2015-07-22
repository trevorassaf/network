#pragma once

#include "v4_namespace.h"
#include "socket_config.h"
#include "socket_builder.h"
#include "../../../socket.h"
#include "../../../socket_config.h"

#include <unordered_map>

class Network::Ip::V4::Socket :
    public Network::Socket,
    public Network::Ip::V4::SocketConfig {

  public:
    enum class Option {
      IPV4_ONLY
    };
    
    typedef std::unordered_map<Option, int, EnumClassKeyer> OsSocketOptionMap;
    typedef std::unordered_map<int, Option> ReverseOsSocketOptionMap;

    static const OsSocketOptionMap OPTION_MAP;
    static const ReverseOsSocketOptionMap REVERSE_OPTION_MAP;

    Network::Ip::V4::Socket * setIsFreeBind(bool is_free_bind) override;
    Network::Ip::V4::Socket * enableFreeBind() override;
    Network::Ip::V4::Socket * disableFreeBind() override;

  protected:
    Network::SocketConfig::AddressFamily getAddressFamily() const override;
    void configureIpv4Socket(Network::Ip::V4::Socket * ipv4_socket) const;

  private:
    static const Level LEVEL;
};
