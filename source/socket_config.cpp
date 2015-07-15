#include "../headers/socket_config.h"

#include <netdb.h>

const Network::SocketConfig::OsSocketAddressFamilyMap
Network::SocketConfig::ADDRESS_FAMILY_MAP = {
  {Network::SocketConfig::AddressFamily::IPV4, AF_INET},
  {Network::SocketConfig::AddressFamily::IPV6, AF_INET6}
};

const Network::SocketConfig::ReverseOsSocketAddressFamilyMap
Network::SocketConfig::REVERSE_ADDRESS_FAMILY_MAP = {
  {AF_INET, Network::SocketConfig::AddressFamily::IPV4},
  {AF_INET6, Network::SocketConfig::AddressFamily::IPV6}
};

const Network::SocketConfig::TypeMap
Network::SocketConfig::TYPE_MAP = {
  {Network::SocketConfig::Type::TCP, SOCK_STREAM},
  {Network::SocketConfig::Type::UDP, SOCK_DGRAM},
  {Network::SocketConfig::Type::IP, SOCK_RAW}
};

const Network::SocketConfig::ReverseTypeMap
Network::SocketConfig::REVERSE_TYPE_MAP = {
  {SOCK_STREAM, Network::SocketConfig::Type::TCP},
  {SOCK_DGRAM, Network::SocketConfig::Type::UDP},
  {SOCK_RAW, Network::SocketConfig::Type::IP}
};
