#include "../headers/ipv4.h"

#include "../headers/network_except.h"

#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>

const std::string Network::Ipv4::stringifyIpv4(uint32_t ipv4_number) {
  char ipv4_string_buffer[INET_ADDRSTRLEN];
  ::memset(ipv4_string_buffer, '\0', INET_ADDRSTRLEN);
  const char * result = ::inet_ntop(
      AF_INET,
      static_cast<const void *>(&ipv4_number),
      ipv4_string_buffer,
      INET_ADDRSTRLEN
  );

  if (result == nullptr) {
    throw Network::Exception::NetworkRuntimeError(errno);
  }

  return std::string(ipv4_string_buffer, INET_ADDRSTRLEN);
}

uint32_t Network::Ipv4::decodeIpv4String(const std::string & ipv4_str) {
  uint32_t ipv4_num;
  int result = ::inet_pton(
      AF_INET,
      ipv4_str.c_str(),
      static_cast<void *>(&ipv4_num)
  );
  
  switch (result) {
    case 0:
      throw Network::Exception::BadIpAddressString(AF_INET, ipv4_str);
      break;
    case -1:
      throw Network::Exception::NetworkRuntimeError(
          errno,
          "inet_pton address family is incorrect, should be AF_INET"
      );
      break;
  }

  return ipv4_num;
}

Network::Ipv4::Ipv4() : 
    _ipv4Number(htonl(IPV4_LOCALHOST_NUMBER)),
    _ipv4String(IPV4_LOCALHOST_STRING)
{}

Network::Ipv4::Ipv4(uint32_t ipv4_number) : 
    _ipv4Number(ipv4_number),
    _ipv4String(Network::Ipv4::stringifyIpv4(ipv4_number))
{}

Network::Ipv4::Ipv4(const std::string & ipv4_str) : 
  _ipv4Number(Network::Ipv4::decodeIpv4String(ipv4_str)),
  _ipv4String(ipv4_str)
{}

uint32_t Network::Ipv4::getNumber() const {
  return _ipv4Number;
}

const std::string & Network::Ipv4::toString() const {
  return _ipv4String;
}

bool Network::Ipv4::operator==(const Network::Ipv4 & ipv4) const {
  return ipv4._ipv4Number == _ipv4Number;
}

bool Network::Ipv4::operator!=(const Network::Ipv4 & ipv4) const {
  return !(*this == ipv4);
}
