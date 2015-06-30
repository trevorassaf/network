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
  ::memcpy(
      static_cast<void *>(_ipv6Bytes),
      static_cast<const void *>(ipv6_bytes),
      sizeof(_ipv6Bytes)
  );
}

std::string Network::Ipv6::stringifyBytes(const uint8_t * ipv6_bytes) {
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

const Network::Ipv6 Network::Ipv6::fromColonSeparatedString(
    const std::string & ipv6_str
) {
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

  return Network::Ipv6(ipv6_address.sin6_addr.s6_addr);
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
