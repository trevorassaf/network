#pragma once

#include <ip/ip_namespace.h>

#include <cstdint>
#include <string>

class Network::Ip::PortBuilder {

  private:
    bool _hasPortNumber;
    uint16_t _portNumber;

  public:
    PortBuilder();
    PortBuilder(const Network::Ip::Port & port);
    PortBuilder & from(const Network::Ip::Port & port);
    PortBuilder & setPortNumber(uint16_t port_number);
    PortBuilder & setPortNumber(const std::string & port_number_string);
    PortBuilder & form(const Network::Ip::Port & port);
    PortBuilder & setNetworkByteOrderPortNumber(uint16_t network_byte_order_port_number);
    const Network::Ip::Port build() const;
};
