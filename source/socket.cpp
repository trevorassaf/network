#include "../headers/socket.h"

#include "../headers/network_except.h"

#include <cstring>
#include <net/if.h>
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

Network::Socket::~Socket() {
  close();
}

bool Network::Socket::isAcceptor() const {
  return Network::Socket::getOption<bool>(
      Network::Socket::Option::IS_ACCEPTOR
  );
}

Network::SocketConfig::AddressFamily
Network::Socket::getAddressFamily() const {
  int os_address_family = Network::Socket::getOption<int>(
      Network::Socket::Option::DOMAIN    
  );
  return Network::SocketConfig::REVERSE_ADDRESS_FAMILY_MAP.at(os_address_family);
}

int Network::Socket::getError() const {
  return Network::Socket::getOption<int>(
      Network::Socket::Option::ERROR    
  );
}

bool Network::Socket::isBoundToDevice() const {
  const std::string device_name = getBoundDevice();
  return !device_name.empty();
}

Network::SocketConfig *
Network::Socket::bindToDevice(const std::string & device_name) {
  setOption(
      Network::Socket::Option::BIND_TO_DEVICE,
      device_name
  );
  return this;
}

const std::string Network::Socket::getBoundDevice() const {
  return getOption(Network::Socket::Option::BIND_TO_DEVICE); 
}

bool Network::Socket::isRouting() const {
  return getOption<bool>(Network::Socket::Option::IS_ROUTING);
}

Network::SocketConfig *
Network::Socket::setIsRouting(bool is_routing) {
  setOption<bool>(Network::Socket::Option::IS_ROUTING, is_routing);
  return this;
}

Network::SocketConfig *
Network::Socket::enableRouting() {
  setIsRouting(true);
  return this;
}

Network::SocketConfig *
Network::Socket::disableRouting() {
  setIsRouting(false);
  return this;
}

Network::SocketConfig *
Network::Socket::setIsKeepAlive(bool is_keep_alive) {
  setOption<bool>(Network::Socket::Option::IS_KEEP_ALIVE, is_keep_alive);
  return this;
}

Network::SocketConfig *
Network::Socket::enableKeepAlive() {
  setIsKeepAlive(true);
  return this;
}

Network::SocketConfig *
Network::Socket::disableKeepAlive() {
  setIsKeepAlive(false);
  return this;
}

Network::SocketConfig *
Network::Socket::setIsLinger(bool is_linger) {
  setOption<bool>(Network::Socket::Option::IS_LINGER, is_linger);
  return this;
}

Network::SocketConfig *
Network::Socket::enableLinger() {
  setIsLinger(true);
  return this;
}

Network::SocketConfig *
Network::Socket::disableLinger() {
  setIsLinger(false);
  return this;
}

Network::SocketConfig *
Network::Socket::setIsOobInline(bool is_oob_inline) {
  setOption<bool>(Network::Socket::Option::IS_OOB_INLINE, is_oob_inline);
  return this;
}

Network::SocketConfig *
Network::Socket::enableOobInline() {
  setIsOobInline(true);
  return this;
}

Network::SocketConfig *
Network::Socket::disableOobInline() {
  setIsOobInline(false);
  return this;
}

Network::SocketConfig *
Network::Socket::setIsPassCredentials(bool is_pass_creds) {
  setOption<bool>(Network::Socket::Option::IS_PASS_CREDENTIALS, is_pass_creds);
  return this;
}

Network::SocketConfig *
Network::Socket::enablePassCredentials() {
  setIsPassCredentials(true);
  return this;
}

Network::SocketConfig *
Network::Socket::disablePassCredentials() {
  setIsPassCredentials(false);
  return this;
}

Network::SocketConfig *
Network::Socket::setIsReuseAddress(bool is_reuse_addr) {
  setOption<bool>(Network::Socket::Option::IS_REUSE_ADDRESS, is_reuse_addr);
  return this;
}

Network::SocketConfig *
Network::Socket::enableReuseAddress() {
  setIsReuseAddress(true);
  return this;
}

Network::SocketConfig *
Network::Socket::disableReuseAddress() {
  setIsReuseAddress(false);
  return this;
}

Network::SocketConfig *
Network::Socket::setIsTimestampTransmitted(bool is_timestamp_transmitted) {
  setOption<bool>(Network::Socket::Option::IS_TIMESTAMP_TRANSMITTED, is_timestamp_transmitted);
  return this;
}

Network::SocketConfig *
Network::Socket::enableTimestampTransmitted() {
  setIsTimestampTransmitted(true);
  return this;
}

Network::SocketConfig *
Network::Socket::disableTimestampTransmitted() {
  setIsTimestampTransmitted(false);
  return this;
}

Network::SocketConfig *
Network::Socket::setPriority(unsigned int priority) {
  setOption<int>(Network::Socket::Option::PRIORITY, priority);
  return this;
}

unsigned int Network::Socket::getPriority() const {
  return getOption<int>(Network::Socket::Option::PRIORITY);
}

Network::SocketConfig *
Network::Socket::setMaximumReceiveBufferBytes(
    unsigned int rcv_buff_size
) {
  setOption<int>(
      Network::Socket::Option::MAXIMUM_RECEIVED_BUFFER_BYTES,
      rcv_buff_size
  );
  return this;
}

unsigned int Network::Socket::getMaximumReceiveBufferBytes() const {
  return getOption<int>(
      Network::Socket::Option::MAXIMUM_RECEIVED_BUFFER_BYTES    
  );  
}

Network::SocketConfig *
Network::Socket::setMinimumReceiveBufferBytes(
    unsigned int rcv_buff_size
) {
  setOption<int>(
      Network::Socket::Option::MINIMUM_RECEIVED_BUFFER_BYTES,
      rcv_buff_size
  );
  return this;
}

unsigned int Network::Socket::getMinimumReceiveBufferBytes() const {
  return getOption<int>(
      Network::Socket::Option::MINIMUM_RECEIVED_BUFFER_BYTES    
  );  
}

Network::SocketConfig *
Network::Socket::setMaximumSendBufferBytes(
    unsigned int send_buff_size
) {
  setOption<int>(
      Network::Socket::Option::MAXIMUM_SEND_BUFFER_BYTES,
      send_buff_size
  );
  return this;
}

unsigned int Network::Socket::getMaximumSendBufferBytes() const {
  return getOption<int>(
      Network::Socket::Option::MAXIMUM_SEND_BUFFER_BYTES    
  );  
}

Network::SocketConfig *
Network::Socket::setMinimumSendBufferBytes(
    unsigned int send_buff_size
) {
  setOption<int>(
      Network::Socket::Option::MINIMUM_SEND_BUFFER_BYTES,
      send_buff_size
  );
  return this;
}

unsigned int Network::Socket::getMinimumSendBufferBytes() const {
  return getOption<int>(
      Network::Socket::Option::MAXIMUM_SEND_BUFFER_BYTES    
  );  
}

Network::SocketConfig *
Network::Socket::setReceiveTimeout(const Network::Time & time) {
  timeval os_time = time.toTimeval();
  setOption<timeval>(
      Network::Socket::Option::RECEIVE_TIMEOUT,
      os_time
  );
  return this;
}

const Network::Time
Network::Socket::getReceiveTimeout() const {
  timeval os_time = getOption<timeval>(
      Network::Socket::Option::RECEIVE_TIMEOUT
  );
  return Network::TimeBuilder()
      .from(os_time)
      .build();
}

Network::SocketConfig *
Network::Socket::setSendTimeout(const Network::Time & time) {
  timeval os_time = time.toTimeval();
  setOption<timeval>(
      Network::Socket::Option::SEND_TIMEOUT,
      os_time
  );
  return this;
} 

const Network::Time
Network::Socket::getSendTimeout() const {
  timeval os_time = getOption<timeval>(
      Network::Socket::Option::SEND_TIMEOUT
  );
  return Network::TimeBuilder()
      .from(os_time)
      .build();
}

Network::SocketConfig::Type
Network::Socket::getType() const {
  int os_type = getOption<int>(
      Network::Socket::Option::TYPE    
  );
  return Network::SocketConfig::REVERSE_TYPE_MAP.at(os_type);
}

const Network::Socket::Level Network::Socket::LEVEL =
    Network::Socket::Level::SOCKET;

Network::Socket::Socket(
    unsigned int socket_descriptor
) : 
    _socketDescriptor(socket_descriptor)
{}

template <typename T>
T Network::Socket::getOption(
    Network::Socket::Option option
) const {
  T data;
  socklen_t data_size = sizeof(data);

  int get_sock_opt_result = ::getsockopt(
      _socketDescriptor,
      Network::Socket::LEVEL_MAP.at(Network::Socket::LEVEL),
      Network::Socket::OPTION_MAP.at(option),
      static_cast<void *>(&data),
      &data_size
  );
  if (get_sock_opt_result == -1) {
    throw Network::Exception::NetworkRuntimeError(errno, "Failed during getsockopt()");
  }
  return data;
}

const std::string
Network::Socket::getOption(
    Network::Socket::Option option    
) const {
  socklen_t str_size = IFNAMSIZ + 1;
  char option_value[str_size];
  ::memset(
      option_value,
      '\0',
      str_size
  );
  int get_sock_opt_result = ::getsockopt(
      _socketDescriptor,
      Network::Socket::LEVEL_MAP.at(Network::Socket::LEVEL),
      Network::Socket::OPTION_MAP.at(option),
      option_value,
      &str_size
  );
  if (get_sock_opt_result) {
    throw Network::Exception::NetworkRuntimeError(errno, "Failed during getsockopt() for string");
  }
  return std::string(option_value);
}

void Network::Socket::setOption(
    Network::Socket::Option option,
    const std::string & option_value
) const {
  int set_sock_opt_result = ::setsockopt(
      _socketDescriptor,
      Network::Socket::LEVEL_MAP.at(Network::Socket::LEVEL),
      Network::Socket::OPTION_MAP.at(option),
      option_value.c_str(),
      option_value.size()
  );
  if (set_sock_opt_result == -1) {
    throw Network::Exception::NetworkRuntimeError(errno, "Failed during setsockopt() for string");
  }
}

template <typename T>
void Network::Socket::setOption(
    Option option,
    const T & data 
) const {
  socklen_t data_size = sizeof(data);
  int set_sock_opt_result = ::setsockopt(
      _socketDescriptor,
      Network::Socket::LEVEL_MAP.at(Network::Socket::LEVEL),
      Network::Socket::OPTION_MAP.at(option),
      static_cast<const void *>(&data),
      data_size
  ); 
  if (set_sock_opt_result == -1) {
    throw Network::Exception::NetworkRuntimeError(errno, "Failed during setsockopt()");
  }
}

void Network::Socket::close() const {
  int close_result = ::close(_socketDescriptor);
  if (close_result == -1) {
    throw Network::Exception::NetworkRuntimeError(
        errno,
        "Encountered error while attempting to close socket!"
    );
  }
}
