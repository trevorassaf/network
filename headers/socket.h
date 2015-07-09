#pragma once

#include "../headers/network.h"
#include "../headers/network_except.h"
#include "../headers/host.h"
#include "../headers/client_config.h"
#include "../headers/server_config.h"
#include "../headers/packet.h"

#include <netdb.h>
#include <unordered_map>
#include <cstdint>

class Network::Tcp::Socket {

  private:
    /**
     * Linux socket type.
     */
    static const int TYPE;

    /**
     * Handle for socket system calls.
     */
    uint32_t _socketDescriptor;

    enum class Status {
      CLOSED,
      OPEN,
      LISTENING,
      CONNECTED
    };

    Status _status;

    bool _isReuseAddr;
    bool _isReusePort;
    bool _isKeepAlive;

    const Host * _local;
    const Host * _remote;

    const Network::Host * initHost(const addrinfo * addr);
    
    void open();
    void open(const Network::ClientConfig & host_config);

    Socket(int socket_descriptor, const Network::Host * local);

  public:
    Socket();
    ~Socket();

    Socket & connect(const Network::ServerConfig & named_host_config);


    template <class Tdata> Socket & write(const Network::Packet<Tdata> & packet);
    template <class Tdata> const Network::Packet<Tdata> read() const;

    Socket & listen();
    Socket & listen(const Network::ClientConfig & client_config);
    Socket accept() const;
    Socket & close();

    const Network::Host * getRemote() const;
    const Network::Host * getLocal() const;

};
