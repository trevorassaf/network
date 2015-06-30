#include "network.h"

#include "ipv4.h"

#include <stdint.h>
#include <string>

#define IPV6_NUM_BYTES 0x16

#define IPV4TO6_CONVERSION_NUM_00_BYTES 4
#define IPV4TO6_CONVERSION_NUM_FF_BYTES 4

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
     * @param ipv6_bytes : ipv6 address in network-byte order (IPV6_NUM_BYTES long)
     */
    Ipv6(const uint8_t * ipv6_bytes);
    
    /**
     * Ipv6()
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
     * copyIpv6Bytes()
     * - Copy ipv6_bytes into _ipv6Bytes.
     * @param ipv6_bytes : ipv6 address in network-byte order (IPV6_NUM_BYTES long)
     */
    void copyIpv6Bytes(const uint8_t ipv6_bytes);

  public:
    /**
     * fromBytes()
     * @param ipv6_bytes : ipv6 address in network-byte order (IPV6_NUM_BYTES long)
     * @return ipv6 object
     */
    static const Ipv6 * fromBytes(const uint8_t * ipv6_bytes);

    /**
     * fromColonSeparatedString()
     * @param ipv6_str : colon-separated ipv6 string.
     * @return ipv6 object
     */
    static const Ipv6 * fromColonSeparatedString(const std::string & ipv6_str);

    /**
     * fromIpv4()
     * @param ipv4 : ipv4 address that we'll translate to ipv6.
     * @return ipv6 object that represents the ipv4 address
     */
    static const Ipv6 * fromIpv4(const Network::Ipv4 * ipv4);

    /**
     * getBytes()
     * @return ipv6 bytes in network-byte order (IPV6_NUM_BYTES long)
     */
    const uint8_t * getBytes() const;

    /**
     * toString()
     * @return ipv6 address in colon-separated string format.
     */
    const std::string * toString() const;

    /**
     * operator==()
     * @param ipv6 : ipv6 address to compare against.
     * @return true iff _ipv6Bytes are equal. We don't have to check
     *    _ipv6String because it's derived from _ipv6Bytes and generated
     *    internally.
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
