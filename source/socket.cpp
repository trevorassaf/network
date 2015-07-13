#include "../headers/socket.h"

#include "../headers/network_except.h"

#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

const Network::Socket::OsSocketOptionMap Network::Socket::OPTION_MAP = {
  {Network::Socket::Option::DOMAIN, SO_DOMAIN},
  {Network::Socket::Option::ERROR, SO_ERROR},
  {Network::Socket::Option::BIND_TO_DEVICE, SO_BINDTODEVICE},
  {Network::Socket::Option::IS_ROUTING, SO_DONTROUTE},
  {Network::Socket::Option::IS_KEEP_ALIVE, SO_KEEPALIVE},
  {Network::Socket::Option::IS_LINGER, SO_LINGER},
  {Network::Socket::Option::IS_OOB_INLINE, SO_OOBINLINE},
  {Network::Socket::Option::IS_PASS_CREDENTIALS, SO_PASSCRED},
  {Network::Socket::Option::IS_REUSE_ADDRESS, SO_REUSEADDR},
  {Network::Socket::Option::IS_TIMESTAMP_TRANSMITTED, SO_TIMESTAMP},
  {Network::Socket::Option::PRIORITY, SO_PRIORITY},
  {Network::Socket::Option::PROTOCOL, SO_PROTOCOL},
  {Network::Socket::Option::MAXIMUM_RECEIVED_BUFFER_BYTES, SO_RCVBUF},
  {Network::Socket::Option::MINIMUM_RECEIVED_BUFFER_BYTES, SO_RCVLOWAT},
  {Network::Socket::Option::MAXIMUM_SEND_BUFFER_BYTES, SO_SNDBUF},
  {Network::Socket::Option::MINIMUM_SEND_BUFFER_BYTES, SO_SNDLOWAT},
  {Network::Socket::Option::RECEIVE_TIMEOUT, SO_RCVTIMEO},
  {Network::Socket::Option::SEND_TIMEOUT, SO_SNDTIMEO},
  {Network::Socket::Option::TYPE, SO_TYPE},
};

const Network::Socket::ReverseOsSocketOptionMap Network::Socket::REVERSE_OPTION_MAP = {
  {SO_DOMAIN, Network::Socket::Option::DOMAIN},
  {SO_ERROR, Network::Socket::Option::ERROR},
  {SO_BINDTODEVICE, Network::Socket::Option::BIND_TO_DEVICE},
  {SO_DONTROUTE, Network::Socket::Option::IS_ROUTING},
  {SO_KEEPALIVE, Network::Socket::Option::IS_KEEP_ALIVE},
  {SO_LINGER, Network::Socket::Option::IS_LINGER},
  {SO_OOBINLINE, Network::Socket::Option::IS_OOB_INLINE},
  {SO_PASSCRED, Network::Socket::Option::IS_PASS_CREDENTIALS},
  {SO_REUSEADDR, Network::Socket::Option::IS_REUSE_ADDRESS},
  {SO_TIMESTAMP, Network::Socket::Option::IS_TIMESTAMP_TRANSMITTED},
  {SO_PRIORITY, Network::Socket::Option::PRIORITY},
  {SO_PROTOCOL, Network::Socket::Option::PROTOCOL},
  {SO_RCVBUF, Network::Socket::Option::MAXIMUM_RECEIVED_BUFFER_BYTES},
  {SO_RCVLOWAT, Network::Socket::Option::MINIMUM_RECEIVED_BUFFER_BYTES},
  {SO_SNDBUF, Network::Socket::Option::MAXIMUM_SEND_BUFFER_BYTES},
  {SO_SNDLOWAT, Network::Socket::Option::MINIMUM_SEND_BUFFER_BYTES},
  {SO_RCVTIMEO, Network::Socket::Option::RECEIVE_TIMEOUT},
  {SO_SNDTIMEO, Network::Socket::Option::SEND_TIMEOUT},
  {SO_TYPE, Network::Socket::Option::TYPE},
};

const Network::Socket::OsSocketLevelMap Network::Socket::LEVEL_MAP = {
  {Network::Socket::Level::SOCKET, SOL_SOCKET},
  {Network::Socket::Level::IPV4, IPPROTO_IP},
  {Network::Socket::Level::IPV6, IPPROTO_IPV6},
  {Network::Socket::Level::TCP, IPPROTO_TCP},
  {Network::Socket::Level::UDP, IPPROTO_UDP}
};

const Network::Socket::ReverseOsSocketLevelMap Network::Socket::REVERSE_LEVEL_MAP = {
  {SOL_SOCKET, Network::Socket::Level::SOCKET},
  {IPPROTO_IP, Network::Socket::Level::IPV4},
  {IPPROTO_IPV6, Network::Socket::Level::IPV6},
  {IPPROTO_TCP, Network::Socket::Level::TCP},
  {IPPROTO_UDP, Network::Socket::Level::UDP}
};

const Network::Socket::OsSocketAddressFamilyMap Network::Socket::ADDRESS_FAMILY_MAP = {
  {Network::Socket::AddressFamily::IPV4, AF_INET},
  {Network::Socket::AddressFamily::IPV6, AF_INET6}
};

const Network::Socket::ReverseOsSocketAddressFamilyMap Network::Socket::REVERSE_ADDRESS_FAMILY_MAP = {
  {AF_INET, Network::Socket::AddressFamily::IPV4},
  {AF_INET6, Network::Socket::AddressFamily::IPV6}
};

const Network::Socket::TypeMap Network::Socket::TYPE_MAP = {
  {Network::Socket::Type::TCP, SOCK_STREAM},
  {Network::Socket::Type::UDP, SOCK_DGRAM},
  {Network::Socket::Type::IP, SOCK_RAW}
};

const Network::Socket::ReverseTypeMap Network::Socket::REVERSE_TYPE_MAP = {
  {SOCK_STREAM, Network::Socket::Type::TCP},
  {SOCK_DGRAM, Network::Socket::Type::UDP},
  {SOCK_RAW, Network::Socket::Type::IP}
};

bool Network::Socket::isAcceptor() const {

}

template <typename T>
T Network::Socket::getOption(const std::string & error_str) const {
  T data;
  socklen_t data_size = sizeof(data);

  int get_sock_opt_result = ::getsockopt(
    _socketDescriptor,
            
  );
}

const Network::Socket::Level Network::Socket::LEVEL =
    Network::Socket::Level::SOCKET;

void Network::Socket::close() const {
  int close_result = ::close(_socketDescriptor);
  if (close_result == -1) {
    throw Network::Exception::NetworkRuntimeError(
        errno,
        "Encountered error while attempting to close socket!"
    );
  }
}
