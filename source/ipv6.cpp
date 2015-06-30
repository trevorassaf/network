#include "../headers/ipv6.h"

#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>

Network::Ipv6::Ipv6(
    const uint8_t * ipv6_bytes
) :
    _ipv6String(Network::Ipv6::stringifyBytes(ipv6_bytes))
{
  copyIpv6Bytes(ipv6_bytes);
}

Network::Ipv6::Ipv6(
    const uint8_t * ipv6_bytes,
    const std::string & ipv6_str
) :
    _ipv6String(ipv6_str)
{
  copyIpv6Bytes(ipv6_bytes);
}

void Network::Ipv6::copyIpv6Bytes(const uint8_t ipv6_bytes) {
  ::memcpy(
      static_cast<void *>(_ipv6Bytes),
      static_cast<const void *>(ipv6_bytes),
      sizeof(_ipv6Bytes)
  );
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

const Network::Ipv6 * Network::Ipv6::fromBytes(const uint8_t * ipv6_bytes) {
  return new Network::Ipv6(ipv6_bytes);
}

const Network::Ipv6 * Network::Ipv6::fromColonSeparatedString(const std::string & ipv6_str) {
  struct sockaddr_in6 ipv6_address;  
  ::memset(
      static_cast<void *>(&ipv6_address),
      0,
      sizeof(ipv6_address)
  );
  
  int result = ::inet_pton(
      AF_INET6,
      ipv6_str.c_str(),
      static_cast<void *>(&ipv6_address)
  );

  if (result != 1) {
    // throw Network::Exception::BadIpv6AddressString(result, ::errno, ipv6_str); 
  }

  return new Network::Ipv6(ipv6_address.sin6_addr.s6_addr, ipv6_str);
}

const Network::Ipv6 * Network::Ipv6::fromIpv4(const Network::Ipv4 * ipv4) {
  uint8_t ipv6_bytes[IPV6_NUM_BYTES];
  uint32_t ipv4_number = ipv4->getNumber();
  const uint8_t * ipv4_ptr = static_cast<const uint8_t *>(
      static_cast<const void *>(&ipv4_number));
  for (int i = 0; i < IPV6_NUM_BYTES; ++i) {
    ipv6_bytes[i] = *ipv4_ptr++;
  } 
}

const uint8_t * Network::Ipv6::getBytes() const {
  return _ipv6Bytes;
}

const std::string * Network::Ipv6::toString() const {
  return &_ipv6String;  
}

bool Network::Ipv6::operator==(const Ipv6 & ipv6) const {
  return ::memcmp(_ipv6Bytes, ipv6.getBytes(), IPV6_NUM_BYTES) == 0;
}

bool Network::Ipv6::operator!=(const Ipv6 & ipv6) const {
  return !(*this == ipv6);
}
