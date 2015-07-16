#pragma once

#include "socket.h"
#include "../../../packet.h"

class Network::Ip::Tcp::Connection :
    public Network::Ip::Tcp::Socket {

  private:
    const Network::Host _localHost;
    const Network::Host _remoteHost;

    friend class Connection;
    Connection(
        const Network::Host & local_host,
        const Network::Host & remote_host
    );

  public:
    const Network::Host & getLocalHost() const;
    const Network::Host & getRemoteHost() const;
    
    template <typename Tdata>
    Network::Packet<Tdata> read<Tdata>() const;

    template <typename Tdata>
    void write<Tdata>(const Network::Packet<Tdata> & packet) const;
};
