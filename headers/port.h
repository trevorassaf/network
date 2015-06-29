#pragma once

#include <cstdint>
#include <string>

class Network::Port {

  private:
    /**
     * Port number in host-byte order.
     */
    const uint16_t _port; 

  public:
    static const Port buildFromHostByteOrderNumber(uint16_t port_num);
    static const Port buildFromNetworkByteOrderNumber(uint16_t port_num);
    static const Port buildFromString(const std::string & port_num);

    uint16_t getHostByteOrderNumber() const;
    uint16_t getNetworkByteOrderNumber() const;
    const std::string toString() const;
};
