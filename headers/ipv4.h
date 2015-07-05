#pragma once

#include "network.h"

#include <stdint.h>
#include <string>

#define IPV4_NUM_BYTES 4

#define IPV4_LOCALHOST_NUMBER 0xFF000001 // network-byte-order
#define IPV4_LOCALHOST_STRING "127.0.0.1"

class Network::Ipv4 {

  private:
    /**
     * Ipv4 numerical address in network-byte order.
     */
    uint32_t _ipv4Number;
    
    /**
     * Ipv4 string address in dotted decimal format.
     */
    std::string _ipv4String;
   
    /**
     * stringifyIpv4()
     * @param ipv4_number : ipv4 numerical address in network-byte order.
     * @return dotted decimal ipv4 address string
     */
    static const std::string stringifyIpv4(uint32_t ipv4_number);

    /**
     * decodeIpv4String()
     * @param ipv4_str : ipv4 address in dotted-decimal string format.
     * @return numeric ipv4 address in network byte order
     */
    static uint32_t decodeIpv4String(const std::string & ipv4_str);

  public:
    /**
     * Ipv4()
     * - Defaults to localhost address.
     */
    Ipv4();

    /**
     * Ipv4()
     * @param ipv4_number : ipv4 number in network-byte order
     */
    Ipv4(uint32_t ipv4_number);

    /**
     * Ipv4()
     * @param ipv4_str : ipv4 string in dotted-decimal form
     */
    Ipv4(const std::string & ipv_str);

    /**
     * getNumber()
     * @return ipv4 numerical address in network-byte order
     */
    uint32_t getNumber() const;

    /**
     * isLocalHost()
     * @return true iff this address represents localhost.
     */
    bool isLocalHost() const;

    /**
     * toString()
     * @return string representation of ipv4 address in dotted decimal format.
     */
    const std::string & toString() const;

    /**
     * operator==()
     * @param ipv4 : peer ipv4 object
     * @return true iff _ipv4Number fields are equal. No need to check _ipv4String
     *    fields b/c these are derived internally from _ipv4Number.
     */
    bool operator==(const Ipv4 & ipv4) const;
    
    /**
     * operator!=()
     * @param ipv4 : peer ipv4 object
     * @return true iff _ipv4Number fields are different. No need to check _ipv4String
     *    fields b/c these are derived internally from _ipv4Number.
     */
    bool operator!=(const Ipv4 & ipv4) const;
};
