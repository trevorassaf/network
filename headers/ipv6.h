#include "network.h"

#include <stdint.h>
#include <string>

#define IPV6_NUM_BYTES 0x16

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
     * Ipv6()
     * @param ipv6_bytes : ipv6 address in network-byte order (IPV6_NUM_BYTES long)
     */
    Ipv6(const uint8_t * ipv6_bytes);

    /**
     * stringifyBytes()
     * @param ipv6_bytes : ipv6 address in network-byte order (IPV6_NUM_BYTES long)
     * @return ipv6 address string in colon-separated format.
     */
    std::string stringifyBytes(const uint8_t * ipv6_bytes);

  public:
    /**
     * fromBytes()
     * @param ipv6_bytes : ipv6 address in network-byte order (IPV6_NUM_BYTES long)
     * @return ipv6 object
     */
    static const Ipv6 fromBytes(const uint8_t * ipv6_bytes);

    /**
     * fromColonSeparatedString()
     * @param ipv6_str : colon-separated ipv6 string.
     * @return ipv6 object
     */
    static const Ipv6 fromColonSeparatedString(const std::string & ipv6_str);

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
