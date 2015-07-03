#pragma once

#include "network.h"

#include "ipv4.h"

#include <stdint.h>
#include <string>

#define IPV6_NUM_BYTES 0x16

#define IPV4TO6_00_BYTE_COUNT 8
#define IPV4TO6_FF_BYTE_COUNT 4
#define IPV4TO6_PREFIX "::ffff:"

#define IPV6_LOCALHOST_STRING "::1"

class Network::Ipv6 {

  private:
    /**
     * Ipv6 number in network-byte order.
     */
    uint8_t _ipv6Bytes[IPV6_NUM_BYTES];
    
    /**
     * Ipv6 address in colon-separated format.
     */
    std::string _ipv6String;

    /**
     * stringifyBytes()
     * @param ipv6_bytes : ipv6 address in network-byte order (IPV6_NUM_BYTES long)
     * @return ipv6 address string in colon-separated format.
     */
    static const std::string stringifyBytes(const uint8_t * ipv6_bytes);

    /**
     * decodeIpv6String()
     * - Translate ipv6 string to numeric ipv6 address. 
     * @param ipv6_string : string ipv6 address.
     * @param ipv6_bytes : buffer in which to store ipv6 bytes. Must be at least
     *    IPV6_NUM_BYTES long.
     */
    static void decodeIpv6String(const std::string & ipv6_str, uint8_t * ipv6_bytes);

    /**
     * decodeIpv6String()
     * - Translate ipv6 string to numeric ipv6 address and copy numeric address
     *      into '_ipv6Bytes'.
     * @param ipv6_string : string ipv6 address.
     */
    void decodeIpv6String(const std::string & ipv6_string);

    /**
     * setIpv6Bytes()
     * - Copy ipv6_bytes into _ipv6Bytes.
     * @param ipv6_bytes : ipv6 address in network-byte order (IPV6_NUM_BYTES long)
     */
    void setIpv6Bytes(const uint8_t * ipv6_bytes);

    /**
     * translateIpv4String()
     * @param ipv4_str : ipv4 address string. MUST be correct (should come directly
     *    from Ipv4 object b/c it ensures string validity)
     */
    static const std::string translateIpv4String(const std::string & ipv4_str);

    /**
     * translateIpv4Number()
     * - Translate ipv4 to compatible ipv6 and copy to '_ipv6Bytes'.
     * @param ipv4_num : network-byte order ipv4 numeric address.
     * @param ipv6_bytes : ipv6 address in network-byte order (IPV6_NUM_BYTES long)
     */
    static void translateIpv4Number(uint32_t ipv4_num, uint8_t * ipv6_bytes);
    
    /**
     * translateIpv4Number()
     * - Translate ipv4 to compatible ipv6 and copy to '_ipv6Bytes'.
     * @param ipv4_num : network-byte order ipv4 numeric address.
     * @param ipv6_bytes : ipv6 address in network-byte order (IPV6_NUM_BYTES long)
     */
    void translateIpv4Number(uint32_t ipv4_num);

  public:
    /**
     * Ipv6()
     * - Initialize to localhost.
     */
    Ipv6();

    /**
     * Ipv6()
     * - Copies ipv6_byte data to internal buffer.
     * @param ipv6_bytes : ipv6 address in network-byte order (IPV6_NUM_BYTES long)
     */
    Ipv6(const uint8_t * ipv6_bytes);

    /**
     * Ipv6()
     * @param ipv6_str : ipv6 address in presentation format.
     */
    Ipv6(const std::string & ipv6_str);
     
    /* Ipv6()
     * - Create ipv4 object that's compatible with the provided 'ipv4'
     * @param ipv4 : ipv4 address
     */
    Ipv6(const Network::Ipv4 & ipv4);

    /**
     * getBytes()
     * @return ipv6 bytes in network-byte order (IPV6_NUM_BYTES long)
     */
    const uint8_t * getBytes() const;

    /**
     * toString()
     * @return ipv6 address in colon-separated string format.
     */
    const std::string & toString() const;

    /**
     * operator==()
     * @param ipv6 : ipv6 address to compare against.
     * @return true iff _ipv6Bytes are equal. We don't have to check
     *    _ipv6String because it's derived from _ipv6Bytes and generated
     *    internally. Also, ipv6 numeric addresses are not bijective with
     *    presentation format.
     */
    bool operator==(const Ipv6 & ipv6) const;

    /**
     * operator!=()
     * @param ipv6 : ipv6 address to compare against.
     * @return true iff _ipv6Bytes are different. We don't have to check
     *    _ipv6String because it's derived from _ipv6Bytes and generated
     *    internally.
     */
    bool operator!=(const Ipv6 & ipv6) const;
};
