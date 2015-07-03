#pragma once

#include "network.h"

#include <string>

#define DEFAULT_PORT_NUMBER 0

class Network::Port {

  private:
    /**
     * Port number in network-byte order.
     */
    uint16_t _portNumber; 

    /**
     * Port string
     */
    std::string _portString;

    /**
     * stringifyPort()
     * @param port_number : network-byte order port number.
     * @return string port number
     */
    static const std::string stringifyPort(uint16_t port_number);

    /**
     * decodePort()
     * @param port_str : port in human-readable string format
     * @return numeric port address in network-byte order
     */
    uint16_t decodePort(const std::string & port_str);

    /**
     * Port()
     * @param port_number : network-byte order port number.
     * @param port_string : string represenation of port.
     */
    Port(uint16_t port_number, const std::string & port_string);

  public:
    /**
     * Port()
     * - Initializes port to default value.
     */
    Port();

    /**
     * Port()
     * @param port_number : network-byte order port number.
     */
    Port(uint16_t port_number);
    
    /**
     * Port()
     * @param port_str : human-readable port string.
     */
    Port(const std::string & port_str);
    
    /**
     * getNumber()
     * @return network-byte order for port number
     */
    uint16_t getNumber() const;

    /**
     * toString()
     * @return port number in human-readable string format 
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
