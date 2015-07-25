#pragma once

#include "tcp_ipv4_namespace.h"
#include "../ip/ipv4/host.h"
#include "../packets/packet.h"
#include "../system_callers/abstract_callers/caller_modules/system_connection_module.h"

class Network::TcpIpv4Socket::Connection {
  
  private:
    Network::SystemConnectionModule * _systemConnectionModule;
    const Network::Ip::V4::Host * _localHost;
    const Network::Ip::V4::Host * _remoteHost;
    void close();

  public:
    Connection(
        Network::SystemConnectionModule * _systemConnectionModule,
        const Network::Ip::V4::Host * local_host,
        const Network::Ip::V4::Host * remote_host
    );

    ~Connection();
    
    const Network::Ip::V4::Host * getLocalHost() const;
    const Network::Ip::V4::Host * getRemoteHost() const;
    
    template <typename Tdata> void write(const Network::Packet<Tdata> * data) const;
    template <typename Tdata> const Network::Packet<Tdata> * read() const;
};
