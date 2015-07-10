#include "../headers/ipv6.h"

#include "../headers/network_except.h"

#include <errno.h>
#include <cassert>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>

#include <iostream>

const std::string Network::Ipv6::stringifyBytes(const uint8_t * ipv6_bytes) {
  in6_addr ipv6_addr;
  ::memcpy(
      static_cast<void *>(&ipv6_addr.s6_addr),
      static_cast<const void *>(ipv6_bytes),
      IPV6_NUM_BYTES
  );

  char ipv6_string_buffer[INET6_ADDRSTRLEN];
  ::memset(ipv6_string_buffer, '\0', INET6_ADDRSTRLEN);

  const char * result = ::inet_ntop(
      AF_INET6,
      static_cast<const void *>(&ipv6_addr),
      ipv6_string_buffer,
      INET6_ADDRSTRLEN
  );

  if (!result) {
    throw Network::Exception::NetworkRuntimeError(errno); 
  }

  return std::string(ipv6_string_buffer, INET6_ADDRSTRLEN);
}

void Network::Ipv6::decodeIpv6String(
    const std::string & ipv6_str,
    uint8_t * ipv6_bytes
) {
  ::memset(
      static_cast<void *>(ipv6_bytes),
      0,
      IPV6_NUM_BYTES 
  );
  in6_addr ipv6_addr;
  
  // Validate ipv4 address
  int result = ::inet_pton(
      AF_INET6,
      ipv6_str.c_str(),
      static_cast<void *>(&ipv6_addr)
  );
 
  switch (result) {
    case 0:
      throw Network::Exception::BadIpAddressString(AF_INET6, ipv6_str);
      break;
    case -1:
      throw Network::Exception::NetworkRuntimeError(
          errno,
          "inet_pton address family is incorrect, should be AF_INET6"
      );
      break;
  }

  ::memcpy(
      static_cast<void *>(ipv6_bytes),
      static_cast<const void *>(&ipv6_addr),
      IPV6_NUM_BYTES
  );
}

void Network::Ipv6::decodeIpv6String(const std::string & ipv6_str) {
  Network::Ipv6::decodeIpv6String(ipv6_str, _ipv6Bytes);
}

void Network::Ipv6::setIpv6Bytes(const uint8_t * ipv6_bytes) {
  ::memcpy(
      static_cast<void *>(_ipv6Bytes),
      static_cast<const void *>(ipv6_bytes),
      IPV6_NUM_BYTES 
  );
}

const std::string Network::Ipv6::translateIpv4String(
    const std::string & ipv4_str
) {
  return IPV4TO6_PREFIX + ipv4_str; 
}

void Network::Ipv6::translateIpv4Number(
    uint32_t ipv4_num,
    uint8_t * ipv6_bytes
) {
  const uint8_t * ipv4_ptr = static_cast<const uint8_t *>(
      static_cast<const void *>(&ipv4_num)
  );

  // Copy ipv4 address in network byte order
  unsigned int byte_index = 0;
  unsigned int terminal_byte_index = IPV4_NUM_BYTES;

  while (byte_index < terminal_byte_index) {
    ipv6_bytes[byte_index++] = *ipv4_ptr++;
  }

  // Copy FF bytes
  terminal_byte_index += IPV4TO6_FF_BYTE_COUNT;

  while (byte_index < terminal_byte_index) {
    ipv6_bytes[byte_index++] = 0xFF;
  }

  // Copy 00 bytes
  terminal_byte_index += IPV4TO6_00_BYTE_COUNT;

  while (byte_index < terminal_byte_index) {
    ipv6_bytes[byte_index++] = 0x00;
  }

  assert(terminal_byte_index == IPV6_NUM_BYTES);
}

void Network::Ipv6::translateIpv4Number(uint32_t ipv4_num) {
  Network::Ipv6::translateIpv4Number(ipv4_num, _ipv6Bytes);
}

Network::Ipv6::Ipv6() : _ipv6String(IPV6_LOCALHOST_STRING) {
  decodeIpv6String(_ipv6String); 
}

Network::Ipv6::Ipv6(const uint8_t * ipv6_bytes) :
    _ipv6String(Network::Ipv6::stringifyBytes(ipv6_bytes))
{
  setIpv6Bytes(ipv6_bytes);
}

Network::Ipv6::Ipv6(const std::string & ipv6_str) : _ipv6String(ipv6_str) {
  Network::Ipv6::decodeIpv6String(ipv6_str);
}

Network::Ipv6::Ipv6(const Network::Ipv4 & ipv4) :
    _ipv6String(
        Network::Ipv6::translateIpv4String(
            ipv4.toString()
        )
    )    
{
  translateIpv4Number(ipv4.getNumber());
}

const uint8_t * Network::Ipv6::getBytes() const {
  return _ipv6Bytes;
}

const std::string & Network::Ipv6::toString() const {
  return _ipv6String;  
}

bool Network::Ipv6::operator==(const Ipv6 & ipv6) const {
  return ::memcmp(_ipv6Bytes, ipv6.getBytes(), IPV6_NUM_BYTES) == 0;
}

bool Network::Ipv6::operator!=(const Ipv6 & ipv6) const {
  return !(*this == ipv6);
}
