#pragma once

#include "../headers/network.h"
#include <cstdint>

class Network::Socket {

  private:
    enum class State {
      
      CONNECTED, 
    };

    /**
     * Handle for socket system calls.
     */
    uint32_t _socketDescriptor;

  public:

    Socket & setClient(const std::Host & client):
};
