#pragma once

#include "network.h"
#include "socket.h"
#include "socket_config.h"
#include "time.h"

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

    bool _isMaximumReceiveBufferBytesSet;
    unsigned int _maximumReceiveBufferBytes;

    bool _isMinimumReceiveBufferBytesSet;
    unsigned int _minimumReceiveBufferBytes;

    bool _isMaximumSendBufferBytesSet;
    unsigned int _maximumSendBufferBytes;
    
    bool _isMinimumSendBufferBytesSet;
    unsigned int _minimumSendBufferBytes;

    bool _isReceiveTimeoutSet;
    Network::TimeBuilder _receiveTimeoutBuilder;
    
    bool _isSendTimeoutSet;
    Network::TimeBuilder _sendTimeoutBuilder;

    bool _isBoundToDevice;
    std::string _boundDeviceName;

    void setOptions(Network::Socket * socket) const;

    int getAddressFamilyForOs() const;
    int getTypeForOs() const;
    int getProtocolForOs() const;

  protected:
    int openSocket() const;

  public:
    virtual Network::Socket * build() const = 0;
    
    // Open hooks
    virtual Network::SocketConfig::Type getType() const = 0;
    virtual Network::SocketConfig::AddressFamily getAddressFamily() const = 0;
    virtual int getProtocol() const = 0; 

    // Bind hooks
    
    
    SocketBuilder();

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

    Network::SocketConfig * setMaximumReceiveBufferBytes(unsigned int rcv_buff_size) override;

    Network::SocketConfig * setMinimumReceiveBufferBytes(unsigned int min_rcv_win_bytes) override;

    Network::SocketConfig * setMaximumSendBufferBytes(unsigned int max_send_buffer) override;

    Network::SocketConfig * setMinimumSendBufferBytes(unsigned int max_send_buffer) override;

    Network::SocketConfig * setReceiveTimeout(const Network::Time & time) override;

    Network::SocketConfig * setSendTimeout(const Network::Time & time) override;

    Network::SocketConfig * bindToDevice(const std::string & device_name) override;
};
