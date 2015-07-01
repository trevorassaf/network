#include "../headers/ipv6.h"

#include <cassert>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>

Network::Ipv6::Ipv6(
    const uint8_t * ipv6_bytes,
    const std::string & ipv6_str
) :
    _ipv6String(ipv6_str)
{
  copyIpv6Bytes(ipv6_bytes);
}

const std::string Network::Ipv6::stringifyBytes(const uint8_t * ipv6_bytes) {
  char ipv6_string_buffer[INET6_ADDRSTRLEN];
  ::memset(ipv6_string_buffer, '\0', INET6_ADDRSTRLEN);
  ::inet_ntop(
      AF_INET6,
      static_cast<const void *>(&ipv6_bytes),
      ipv6_string_buffer,
      INET6_ADDRSTRLEN
  );

  return std::string(ipv6_string_buffer, INET6_ADDRSTRLEN);
}

void Network::Ipv6::decodeString(const std::string & ipv6_str, uint8_t * ipv6_bytes) {
  ::memset(
      static_cast<void *>(ipv6_bytes),
      0,
      IPV6_NUM_BYTES 
  ); 

  int result = ::inet_pton(
      AF_INET6,
      ipv6_str.c_str(),
      static_cast<void *>(&ipv6_bytes)
  );

  if (result != 1) {
    // throw Network::Exception::BadIpv6AddressString(result, ::errno, ipv6_str);
  }
}

void Network::Ipv6::copyIpv6Bytes(const uint8_t * ipv6_bytes) {
  ::memcpy(
      static_cast<void *>(_ipv6Bytes),
      static_cast<const void *>(ipv6_bytes),
      sizeof(_ipv6Bytes)
  );
}

const Network::Ipv6 * Network::Ipv6::fromBytes(const uint8_t * ipv6_bytes) {
  return new Network::Ipv6(ipv6_bytes);
}

const Network::Ipv6 * Network::Ipv6::fromString(const std::string & ipv6_str) {
  struct sockaddr_in6 ipv6_address;  
  Network::Ipv6::decodeString(ipv6_str, &ipv6_address.sin6_addr.s6_addr);
  return new Network::Ipv6(ipv6_address.sin6_addr.s6_addr, ipv6_str);
}

const Network::Ipv6 * Network::Ipv6::fromIpv4(const Network::Ipv4 * ipv4) {
  uint8_t ipv6_bytes[IPV6_NUM_BYTES];
  uint32_t ipv4_number = ipv4->getNumber();
  const uint8_t * ipv4_ptr = static_cast<const uint8_t *>(
      static_cast<const void *>(&ipv4_number)
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

  return new Network::Ipv6(ipv6_bytes);
}

Network::Ipv6::Ipv6() : _ipv6String(IPV6_LOCALHOST_STRING) {
  Network::Ipv6::decodeString(_ipv6String, _ipv6Bytes); 
}

Network::Ipv6::Ipv6(
    const uint8_t * ipv6_bytes
) :
    _ipv6String(Network::Ipv6::stringifyBytes(ipv6_bytes))
{
  copyIpv6Bytes(ipv6_bytes);
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
