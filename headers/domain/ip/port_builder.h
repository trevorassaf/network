#pragma once

#include "../../network.h"
#include "port.h"

#include <cstdint>

#define DYNAMIC_PORT_NUMBER 0
#define DYNAMIC_PORT_STRING "0"

class Network::PortBuilder {

  private:
    bool _hasPort;
    uint16_t _port;

    void validateOrThrow() const;

  public:
    PortBuilder();
    PortBuilder & setPort(uint16_t port);
    PortBuilder & setPort(const std::string & port);
    const Network::Port build() const;
    const Network::Port * buildNew() const;
};
