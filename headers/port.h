#pragma once

#include "network.h"

#include <string>

class Network::Port {

  private:
    /**
     * Port number in network-byte order.
     */
    const uint16_t _portNumber; 

    /**
     * Port string
     */
    const std::string _portString;

    /**
     * stringifyPort()
     * @param port_number : network-byte order port number.
     * @return string port number
     */
    static const std::string stringifyPort(uint16_t port_number);

    /**
     * Port()
     * @param port_number : network-byte order port number.
     * @param port_string : string represenation of port.
     */
    Port(uint16_t port_number, const std::string & port_string);

  public:
    /**
     * Port()
     * @param port_number : network-byte order port number.
     */
    Port(uint16_t port_number);
    
    /**
     * fromString()
     * @param port_string : string representation of port
     * @return port object
     */
    static const Port fromString(const std::string & port_string);

    /**
     * getNumber()
     * @return network-byte order for port number
     */
    uint16_t getNumber() const;

    /**
     * toString()
     * @return string representation of port number
     */
    const std::string & toString() const;

    /**
     * operator==()
     * @param port : peer port to compare against
     * @return true iff _portNumber is equal for both objects. We needn't
     *    test _portString b/c it was internally derived from _portNumber.
     */
    bool operator==(const Port & port) const;
    
    /**
     * operator!=()
     * @param port : peer port to compare against
     * @return true iff _portNumber is different for both objects. We needn't
     *    test _portString b/c it was internally derived from _portNumber.
     */
    bool operator!=(const Port & port) const;
};
