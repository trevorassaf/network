#pragma once

#include "network.h"

class Network::SocketConfig {

  public:
    virtual Network::SocketConfig * setIsRouting(bool is_routing) = 0;
    virtual Network::SocketConfig * enableRouting() = 0;
    virtual Network::SocketConfig * disableRouting() = 0;

    virtual Network::SocketConfig * setIsKeepAlive(bool is_keep_alive) = 0;
    virtual Network::SocketConfig * enableKeepAlive() = 0;
    virtual Network::SocketConfig * disableKeepAlive() = 0;

    virtual Network::SocketConfig * setIsLinger(bool is_linger) = 0;
    virtual Network::SocketConfig * enableLinger() = 0;
    virtual Network::SocketConfig * disableLinger() = 0;

    virtual Network::SocketConfig * setIsOobInline(bool is_oob_inline) = 0;
    virtual Network::SocketConfig * enableOobInline() = 0;
    virtual Network::SocketConfig * disableOobInline() = 0;

    virtual Network::SocketConfig * setIsPassCredentials(bool is_pass_cred) = 0;
    virtual Network::SocketConfig * enablePassCredentials() = 0;
    virtual Network::SocketConfig * disablePassCredentials() = 0;

    virtual Network::SocketConfig * setIsReuseAddress(bool is_reuse_addr) = 0;
    virtual Network::SocketConfig * enableReuseAddress() = 0;
    virtual Network::SocketConfig * disableReuseAddress() = 0;

    virtual Network::SocketConfig * setIsTimestampTransmitted(bool is_timestamp_transmitted) = 0;
    virtual Network::SocketConfig * enableTimestampTransmitted() = 0;
    virtual Network::SocketConfig * disableTimestampTransmitted() = 0;

    virtual Network::SocketConfig * setPriority(unsigned int priority) = 0;

    virtual Network::SocketConfig * setMaximumReceivedBufferBytes(unsigned int rcv_buff_size) = 0;

    virtual Network::SocketConfig * setMinimumReceivedBufferBytes(unsigned int min_rcv_win_bytes) = 0;

    virtual Network::SocketConfig * setMaximumSendBufferBytes(unsigned int max_send_buffer) = 0;

    virtual Network::SocketConfig * setMinimumSendBufferBytes(unsigned int max_send_buffer) = 0;

    virtual Network::SocketConfig * setReceiveTimeout(unsigned int seconds, unsigned int micro_seconds) = 0;
    virtual Network::SocketConfig * setSendTimeout(unsigned int seconds, unsigned int micro_seconds) = 0;
};
