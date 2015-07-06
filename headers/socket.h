#pragma once

#include "../headers/network.h"
#include "../headers/network_except.h"
#include "../headers/host.h"
#include "../client_config.h"
#include "../server_config.h"

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

    class enum Status {
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

  public:
    Socket();
    Socket & open();
    Socket & open(const Network::ClientConfig & client_config);

    Socket & connect(const Network::ServerConfig & server_config);

    // Socket & write();
    // Serializeable read()

   Socket & listen();
    
   Socket accept() const;
  
   Socket & close();
  
   const Network::Host & getServer() const;
   const Network::Host & getClient() const;

};
