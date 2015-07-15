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
    _isMaximumReceiveBufferBytesSet(false),
    _isMinimumReceiveBufferBytesSet(false),
    _isMaximumSendBufferBytesSet(false),
    _isMinimumSendBufferBytesSet(false),
    _isReceiveTimeoutSet(false),
    _isSendTimeoutSet(false),
    _isBoundToDevice(false)
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

  if (_isPrioritySet) {
    socket->setPriority(_priority);
  }

  if (_isMaximumReceiveBufferBytesSet) {
    socket->setMaximumReceiveBufferBytes(_maximumReceiveBufferBytes);
  }
  
  if (_isMinimumReceiveBufferBytesSet) {
    socket->setMinimumReceiveBufferBytes(_maximumReceiveBufferBytes);
  }
  
  if (_isMaximumSendBufferBytesSet) {
    socket->setMaximumSendBufferBytes(_maximumSendBufferBytes);
  }
  
  if (_isMinimumSendBufferBytesSet) {
    socket->setMinimumSendBufferBytes(_maximumSendBufferBytes);
  }

  if (_isReceiveTimeoutSet) {
    socket->setReceiveTimeout(_receiveTimeoutBuilder.build());
  }
  
  if (_isSendTimeoutSet) {
    socket->setSendTimeout(_receiveTimeoutBuilder.build());
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

Network::SocketConfig * 
Network::SocketBuilder::setMaximumReceiveBufferBytes(
    unsigned int rcv_buff_size
) {
  _isMaximumReceiveBufferBytesSet = true;
  _maximumReceiveBufferBytes = rcv_buff_size;
  return this;
}

Network::SocketConfig * 
Network::SocketBuilder::setMinimumReceiveBufferBytes(
    unsigned int rcv_buff_size
) {
  _isMinimumReceiveBufferBytesSet = true;
  _minimumReceiveBufferBytes = rcv_buff_size;
  return this;
}

Network::SocketConfig * 
Network::SocketBuilder::setMaximumSendBufferBytes(
    unsigned int send_buff_size
) {
  _isMaximumSendBufferBytesSet = true;
  _maximumSendBufferBytes = send_buff_size;
  return this;
}

Network::SocketConfig * 
Network::SocketBuilder::setMinimumSendBufferBytes(
    unsigned int send_buff_size
) {
  _isMinimumSendBufferBytesSet = true;
  _minimumSendBufferBytes = send_buff_size;
  return this;
}

Network::SocketConfig *
Network::SocketBuilder::setReceiveTimeout(
    const Network::Time & time
) {
  _isReceiveTimeoutSet = true;
  _receiveTimeoutBuilder.from(time);
  return this;
}

Network::SocketConfig *
Network::SocketBuilder::setSendTimeout(
    const Network::Time & time
) {
  _isSendTimeoutSet = true;
  _sendTimeoutBuilder.from(time);
  return this;
}

Network::SocketConfig *
Network::SocketBuilder::bindToDevice(
    const std::string & bound_device_name    
) {
  _isBoundToDevice = true;
  _boundDeviceName = bound_device_name;
  return this;
}
