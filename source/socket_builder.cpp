#include "../headers/socket_builder.h"

#include "../headers/network_except.h" 

#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>

Network::SocketBuilder::SocketBuilder() :
    _isRoutingSet(false),
    _isKeepAliveSet(false),
    _isLingerSet(false),
    _isOobInlineSet(false),
    _isPassCredSet(false),
    _isReuseAddrSet(false),
    _isTimestampTransmittedSet(false),
    _isPrioritySet(false),
    _isReceiveBufferSizeSet(false),
    _isMinimumReceiveWindowBytesSet(false),
    _isMaximumSendWindowBytesSet(false)
{}

int Network::SocketBuilder::open() const {
  int open_result = ::socket(
    getAddressFamilyForOs(),
    getTypeForOs(),
    getProtocolForOs()
  );
  if (open_result) {
    throw Network::Exception::NetworkRuntimeError(
        errno,
        "Encountered while attempting to open socket!"
    );
  }
  return open_result;
}

void Network::SocketBuilder::setOptions(Network::Socket * socket) const {
  if (_isRoutingSet) {
    socket->setIsRouting(_isRouting);
  }

  if (_isKeepAliveSet) {
    socket->setIsKeepAlive(_isKeepAlive);
  }

  if (_isLingerSet) {
    socket->setIsLinger(_isLinger);
  }

  if (_isOobInlineSet) {
    socket->setIsOobInline(_isOobInline);
  }

  if (_isPassCredSet) {
    socket->setIsPassCredentials(_isPassCred);
  }

  if (_isReuseAddrSet) {
    socket->setIsReuseAddress(_isReuseAddr);
  }

  if (_isTimestampTransmittedSet) {
    socket->setIsTimestampTransmitted(_isTimestampTransmitted);
  }

  if (_isReceiveBufferSizeSet) {
    socket->setReceivedBufferSize(_receiveBufferSize);
  }

  if (_isMinimumReceiveWindowBytesSet) {
    socket->setMinimumReceiveWindowBytes(_minimumReceivedWindowBytes);
  }

  if (_isMaximumSendWindowBytesSet) {
    socket->setMaximumSendBufferSize(_maximumSendWindowBytes);
  }
}

int Network::SocketBuilder::getAddressFamilyForOs() const {
  return Network::Socket::ADDRESS_FAMILY_MAP.at(getAddressFamily());  
}

int Network::SocketBuilder::getTypeForOs() const {
  return Network::Socket::TYPE_MAP.at(getType());  
}

int Network::SocketBuilder::getProtocolForOs() const {
  return 0; 
}

Network::Socket * Network::SocketBuilder::build() const {
  int socket_descriptor = open();
  Network::Socket * socket = initNewConcreteSocket(socket_descriptor);
  setOptions(socket);
  return socket;
}

Network::SocketConfig * Network::SocketBuilder::setIsRouting(bool is_routing) {
  _isRoutingSet = true;
  _isRouting = is_routing;
  return this;
}

Network::SocketConfig * Network::SocketBuilder::enableRouting() {
  return setIsRouting(true);
}

Network::SocketConfig * Network::SocketBuilder::disableRouting() {
  return setIsRouting(false);
}

Network::SocketConfig * Network::SocketBuilder::setIsKeepAlive(bool is_keep_alive) {
  _isKeepAliveSet = true;
  _isKeepAlive = is_keep_alive;
  return this;
}

Network::SocketConfig * Network::SocketBuilder::enableKeepAlive() {
  return setIsKeepAlive(true);
}

Network::SocketConfig * Network::SocketBuilder::disableKeepAlive() {
  return setIsKeepAlive(false);
}

Network::SocketConfig * Network::SocketBuilder::setIsLinger(bool is_linger) {
  _isLingerSet = true;
  _isLinger = is_linger;
  return this;
}

Network::SocketConfig * Network::SocketBuilder::enableLinger() {
  return setIsLinger(true);
}

Network::SocketConfig * Network::SocketBuilder::disableLinger() {
  return setIsLinger(false);
}

Network::SocketConfig * Network::SocketBuilder::setIsOobInline(bool is_oob_inline) {
  _isOobInlineSet = true;
  _isOobInline = is_oob_inline;
  return this;
}

Network::SocketConfig * Network::SocketBuilder::enableOobInline() {
  return setIsOobInline(true);
}

Network::SocketConfig * Network::SocketBuilder::disableOobInline() {
  return setIsOobInline(false);
}

Network::SocketConfig * Network::SocketBuilder::setIsPassCredentials(bool is_pass_creds) {
  _isPassCredSet = true;
  _isPassCred = is_pass_creds;
  return this;
}

Network::SocketConfig * Network::SocketBuilder::enablePassCredentials() {
  return setIsPassCredentials(true);
}

Network::SocketConfig * Network::SocketBuilder::disablePassCredentials() {
  return setIsPassCredentials(false);
}

Network::SocketConfig * Network::SocketBuilder::setIsReuseAddress(bool is_reuse_addr) {
  _isReuseAddrSet = true;
  _isReuseAddr = is_reuse_addr;
  return this;
}

Network::SocketConfig * Network::SocketBuilder::enableReuseAddress() {
  return setIsReuseAddress(true);
}

Network::SocketConfig * Network::SocketBuilder::disableReuseAddress() {
  return setIsReuseAddress(false);
}

Network::SocketConfig * Network::SocketBuilder::setIsTimestampTransmitted(bool is_timestamp_transmitted) {
  _isTimestampTransmittedSet = true;
  _isTimestampTransmitted = is_timestamp_transmitted;
  return this;
}

Network::SocketConfig * Network::SocketBuilder::enableTimestampTransmitted() {
  return setIsTimestampTransmitted(true);
}

Network::SocketConfig * Network::SocketBuilder::disableTimestampTransmitted() {
  return setIsTimestampTransmitted(false);
}

Network::SocketConfig * Network::SocketBuilder::setPriority(unsigned int priority) {
  _isPrioritySet = true;
  _priority = priority; 
  return this;
}

Network::SocketConfig * Network::SocketBuilder::setReceivedBufferSize(unsigned int rcv_buff_size) {
  _isReceiveBufferSizeSet = true;
  _receiveBufferSize = rcv_buff_size;
  return this;
}

Network::SocketConfig * Network::SocketBuilder::setMinimumReceiveWindowBytes(unsigned int min_rcv_win_bytes) {
  _isMinimumReceiveWindowBytesSet = true;
  _minimumReceivedWindowBytes = min_rcv_win_bytes;
  return this;
}

Network::SocketConfig * Network::SocketBuilder::setMaximumSendBufferSize(unsigned int max_send_buffer_bytes) {
  _isMaximumSendWindowBytesSet = true;
  _maximumSendWindowBytes = max_send_buffer_bytes;
  return this;
}
