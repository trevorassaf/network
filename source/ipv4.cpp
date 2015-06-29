#include "../headers/ipv4.h"

#include <netinet/in.h>
#include <arpa/inet.h>

Network::Ipv4::Ipv4(uint32_t ipv4_number) : _ipv4Number(ipv4_number) {}

const Network::Ipv4 Network::Ipv4::makeFromHostByteOrderNumber(uint32_t ipv4_number) {
  return Network::Ipv4(ipv4_number);
}

const Network::Ipv4 Network::Ipv4::makeFromNetworkByteOrderNumber(uint32_t ipv4_number) {
  return Network::Ipv4(ntohl(ipv4_number));
}

const Network::Ipv4 Network::Ipv4::makeFromDottedDecimalString(const std::string & ipv4_dotted_decimal) {
  uint32_t ipv4_num;
  int result = ::inet_pton(AF_INET, ipv4_dotted_decimal.c_str(), &ipv4_num);
  // if (result == -1) {
  //   throw Network::Exception::BadIpAddress(::errno);
  // }
  return Network::Ipv4::makeFromNetworkByteOrderNumber(ipv4_num);
}

uint32_t Network::Ipv4::getHostByteOrderNumber() const {
  return _ipv4Number;
}

uint32_t Network::Ipv4::getNetworkByteOrderNumber() const {
  return htonl(_ipv4Number);
}

bool Network::Ipv4::operator==(const Network::Ipv4 & ipv4) const {
  return ipv4._ipv4Number == _ipv4Number;
}

bool Network::Ipv4::operator!=(const Network::Ipv4 & ipv4) const {
  return ipv4._ipv4Number != _ipv4Number;
}
