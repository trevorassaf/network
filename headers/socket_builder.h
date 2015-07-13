#pragma once

#include "network.h"
#include "socket.h"
#include "socket_config.h"

class Network::SocketBuilder : Network::SocketConfig {

  private:
    bool _isRoutingSet, _isRouting;
    bool _isKeepAliveSet, _isKeepAlive;
    bool _isLingerSet, _isLinger;
    bool _isOobInlineSet, _isOobInline;
    bool _isPassCredSet, _isPassCred;
    bool _isReuseAddrSet, _isReuseAddr;
    bool _isTimestampTransmittedSet, _isTimestampTransmitted;

    bool _isPrioritySet;
    unsigned int _priority;

    bool _isReceiveBufferSizeSet;
    unsigned int _receiveBufferSize;

    bool _isMinimumReceiveWindowBytesSet;
    unsigned int _minimumReceivedWindowBytes;

    bool _isMaximumSendWindowBytesSet;
    unsigned int _maximumSendWindowBytes;

    int open() const;
    void setOptions(Network::Socket * socket) const;

    int getAddressFamilyForOs() const;
    int getTypeForOs() const;
    int getProtocolForOs() const;

  protected:
    virtual Network::Socket * initNewConcreteSocket(int socket_descriptor) const;

  public:
    virtual Network::Socket::Type getType() const = 0;
    virtual Network::Socket::AddressFamily getAddressFamily() const = 0;
    
    SocketBuilder();
    virtual Network::Socket * build() const;

    Network::SocketConfig * setIsRouting(bool is_routing) override;
    Network::SocketConfig * enableRouting() override;
    Network::SocketConfig * disableRouting() override;

    Network::SocketConfig * setIsKeepAlive(bool is_keep_alive) override;
    Network::SocketConfig * enableKeepAlive() override;
    Network::SocketConfig * disableKeepAlive() override;

    Network::SocketConfig * setIsLinger(bool is_linger) override;
    Network::SocketConfig * enableLinger() override;
    Network::SocketConfig * disableLinger() override;

    Network::SocketConfig * setIsOobInline(bool is_oob_inline) override;
    Network::SocketConfig * enableOobInline() override;
    Network::SocketConfig * disableOobInline() override;

    Network::SocketConfig * setIsPassCredentials(bool is_pass_cred) override;
    Network::SocketConfig * enablePassCredentials() override;
    Network::SocketConfig * disablePassCredentials() override;
    
    Network::SocketConfig * setIsReuseAddress(bool is_reuse_addr) override;
    Network::SocketConfig * enableReuseAddress() override;
    Network::SocketConfig * disableReuseAddress() override;
   
    Network::SocketConfig * setIsTimestampTransmitted(bool is_timestamp_transmitted) override;
    Network::SocketConfig * enableTimestampTransmitted() override;
    Network::SocketConfig * disableTimestampTransmitted() override;

    Network::SocketConfig * setPriority(unsigned int priority) override;

    Network::SocketConfig * setReceivedBufferSize(unsigned int rcv_buff_size) override;

    Network::SocketConfig * setMinimumReceiveWindowBytes(unsigned int min_rcv_win_bytes) override;

    Network::SocketConfig * setMaximumSendBufferSize(unsigned int max_send_buffer) override;
};