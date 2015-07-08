#pragma once

#include "../headers/network.h"
#include "../headers/network_except.h"
#include "../headers/host.h"
#include "../headers/client_config.h"
#include "../headers/server_config.h"

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

    const Host * _client;
    const Host * _server;

    const Network::Host * initHost(const addrinfo * addr);

  public:
    Socket();
    Socket & open();
    Socket & open(const Network::ClientConfig & host_config);
    Socket & connect(const Network::ServerConfig & named_host_config);

    // Socket & write();
    // Serializeable read()

    Socket & listen();
    Socket accept() const;
    Socket & close();

    const Network::Host * getServer() const;
    const Network::Host * getClient() const;

};
