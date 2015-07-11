#pragma once

#include "network.h"

class Network::SocketConfig {

  public:
    virtual bool isAcceptor() const = 0;
    
    virtual int getDomain() const = 0;
    
    virtual int getError() const = 0;
    
    virtual bool isRouting() const = 0;
    virtual void setIsRouting(bool is_routing) = 0;
    virtual void enableRouting() = 0;
    virtual void disableRouting() = 0;

    virtual bool isKeepAlive() const = 0;
    virtual void setIsKeepAlive(bool is_keep_alive) = 0;
    virtual void enableKeepAlive() = 0;
    virtual void disableKeepAlive() = 0;

    virtual bool isLinger() const = 0;
    virtual void setIsLinger(bool is_linger) = 0;
    virtual void enableLinger() = 0;
    virtual void disableLinger() = 0;

    virtual bool isOobInline() const = 0;
    virtual void setIsOobInline(bool is_oob_inline) = 0;
    virtual void enableOobInline() = 0;
    virtual void disableOobInline() = 0;

    virtual bool isPassCredentials() const = 0;
    virtual void setIsPassCredentials(bool is_pass_cred) = 0;
    virtual void enablePassCredentials() = 0;
    virtual void disablePassCredentials() = 0;

    virtual int getPriority() const = 0;
    virtual void setPriority(int priority) = 0;

    virtual int getProtocol() const = 0;

    virtual int getReceiveBufferSize() const = 0;
    virtual void setReceivedBufferSize(int rcv_buff_size) = 0;

    virtual int getMinimumReceivedWindowBytes() const = 0;
    virtual void setMinimumReceiveWindowBytes(int min_rcv_win_bytes) = 0;

    virtual bool isReuseAddress() const = 0;
    virtual void setIsReuseAddress(bool is_reuse_addr) = 0;
    virtual void enableReuseAddress() = 0;
    virtual void disableReuseAddress() = 0;

    virtual int getMaximumSendBufferSize() const = 0; 
    virtual void setMaximumSendBufferSize(int max_send_buffer) = 0;

    virtual bool isTimestampTransmitted() const = 0;
    virtual void setIsTimestampTransmitted(bool is_timestamp_transmitted) = 0;

    virtual int getType() const = 0;
};
