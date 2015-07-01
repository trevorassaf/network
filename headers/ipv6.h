#include "network.h"

#include "ipv4.h"

#include <stdint.h>
#include <string>

#define IPV6_NUM_BYTES 0x16

#define IPV4TO6_00_BYTE_COUNT 8
#define IPV4TO6_FF_BYTE_COUNT 4

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
    const std::string _ipv6String;
    
    /**
     * Ipv6()
     * - Copies ipv6_bytes data to internal buffer.
     * @param ipv6_bytes : ipv6 address in network-byte order (IPV6_NUM_BYTES long)
     * @param ipv6_str : colon-separated ipv6 string.
     */
    Ipv6(const uint8_t * ipv6_bytes, const std::string & ipv6_str);

    /**
     * stringifyBytes()
     * @param ipv6_bytes : ipv6 address in network-byte order (IPV6_NUM_BYTES long)
     * @return ipv6 address string in colon-separated format.
     */
    static const std::string stringifyBytes(const uint8_t * ipv6_bytes);

    /**
     * decodeString()
     * - Translate ipv6 string to numeric ipv6 address.
     * @param ipv6_string : string ipv6 address.
     * @param ipv6_bytes : buffer to which numeric ipv6 is written. Must be IPV6_NUM_BYTES long
     */
    static void decodeString(const std::string & ipv6_string, uint8_t * ipv6_bytes);

    /**
     * copyIpv6Bytes()
     * - Copy ipv6_bytes into _ipv6Bytes.
     * @param ipv6_bytes : ipv6 address in network-byte order (IPV6_NUM_BYTES long)
     */
    void copyIpv6Bytes(const uint8_t * ipv6_bytes);

  public:
    /**
     * fromBytes()
     * - Copies ipv6_bytes data to internal buffer.
     * @param ipv6_bytes : ipv6 address in network-byte order (IPV6_NUM_BYTES long)
     * @return ipv6 object
     */
    static const Ipv6 * fromBytes(const uint8_t * ipv6_bytes);

    /**
     * fromColonSeparatedString()
     * @param ipv6_str : colon-separated ipv6 string.
     * @return ipv6 object
     */
    static const Ipv6 * fromString(const std::string & ipv6_str);

    /**
     * fromIpv4()
     * @param ipv4 : ipv4 address that we'll translate to ipv6.
     * @return ipv6 object that represents the ipv4 address
     */
    static const Ipv6 * fromIpv4(const Network::Ipv4 * ipv4);

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

    /**
     * getBytes()
     * @return ipv6 bytes in network-byte order (IPV6_NUM_BYTES long)
     */
    uint8_t * getBytes() const;

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
