#pragma once

#include "../headers/network.h"
#include "../headers/host.h"

#include <unordered_map>
#include <cstdint>

class Network::Tcp::Socket {

  private:
    /**
     * Handle for socket system calls.
     */
    uint32_t _socketDescriptor;

    class enum Status {
      CLOSED,
      OPEN,
      LISTENING
    };

    Status _status;

    bool _isReuseAddr;
    bool _isReusePort;

    Host _client;
    Host _server;

  public:
    Socket();

    Socket & open();
    Socket & connect(const Host & server);

    // Socket & write();
    // Serializeable read()


    void listen();
    Socket accept() const;
    
    void close();
    
    const Host & getServer() const;
    const Host & getClient() const;

};
