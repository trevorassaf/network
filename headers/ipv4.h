#pragma once

#include "network.h"

#include <cstdint>
#include <string>

class Network::Ipv4 {

  private:
    /**
     * Ipv4 numerical address in host-byte order.
     */
    const uint32_t _ipv4Number;

    /**
     * Ipv4()
     * @param ipv4_number : ipv4 number in host-byte order
     */
    Ipv4(uint32_t ipv4_number);

  public:
    static const Ipv4 makeFromHostByteOrderNumber(uint32_t ipv4_number);
    static const Ipv4 makeFromNetworkByteOrderNumber(uint32_t ipv4_number);
    static const Ipv4 makeFromDottedDecimalString(const std::string & ipv4_dotted_decimal);

    uint32_t getHostByteOrderNumber() const;
    uint32_t getNetworkByteOrderNumber() const;
    bool operator==(const Ipv4 & ipv4) const;
    bool operator!=(const Ipv4 & ipv4) const;
};
