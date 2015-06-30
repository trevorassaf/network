#include "../headers/ipv4.h"

#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>

Network::Ipv4::Ipv4(
    uint32_t ipv4_number
) : 
    _ipv4Number(ipv4_number),
    _ipv4String(Network::Ipv4::stringifyIpv4(ipv4_number))
{}

Network::Ipv4::Ipv4(const Network::Ipv4 & ipv4) {
  _ipv4Number = ipv4._ipv4Number;
  _ipv4String = ipv4._ipv4String;
}

const std::string Network::Ipv4::stringifyIpv4(uint32_t ipv4_number) {
  char ipv4_string_buffer[INET_ADDRSTRLEN];
  ::memset(ipv4_string_buffer, '\0', INET_ADDRSTRLEN);
  ::inet_ntop(
      AF_INET,
      static_cast<const void *>(&ipv4_number),
      ipv4_string_buffer,
      INET_ADDRSTRLEN
  );

  return std::string(ipv4_string_buffer, INET_ADDRSTRLEN);
}

const Network::Ipv4 * Network::Ipv4::fromDottedDecimalString(const std::string & ipv4_dotted_decimal) {
  uint32_t ipv4_num;
  ::inet_pton(AF_INET, ipv4_dotted_decimal.c_str(), &ipv4_num);
  return new Network::Ipv4(ipv4_num);
}

uint32_t Network::Ipv4::getNumber() const {
  return _ipv4Number;
}

bool Network::Ipv4::operator==(const Network::Ipv4 & ipv4) const {
  return ipv4._ipv4Number == _ipv4Number;
}

bool Network::Ipv4::operator!=(const Network::Ipv4 & ipv4) const {
  return !(*this == ipv4);
}
