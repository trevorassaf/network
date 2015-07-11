#pragma once

#include "network.h"
#include "socket_builder.h"
#include "socket_config.h"

class Network::Socket : Network::SocketConfig {

  friend class SocketBuilder;

  private:
    const int _socketDescriptor;

    Socket(int socket_descriptor);

  public:

    bool isAcceptor() const;
    
    int getDomain() const;
    
    int getError() const;
    
    bool isRouting() const;
    void setIsRouting(bool is_routing);
    void enableRouting();
    void disableRouting();

    bool isKeepAlive() const;
    void setIsKeepAlive(bool is_keep_alive);
    void enableKeepAlive();
    void disableKeepAlive();

    bool isLinger() const;
    void setIsLinger(bool is_linger);
    void enableLinger();
    void disableLinger();

    bool isOobInline() const;
    void setIsOobInline(bool is_oob_inline);
    void enableOobInline();
    void disableOobInline();

    bool isPassCredentials() const;
    void setIsPassCredentials(bool is_pass_cred);
    void enablePassCredentials();
    void disablePassCredentials();

    int getPriority() const;
    void setPriority(int priority);

    int getProtocol() const;

    int getReceiveBufferSize() const;
    void setReceivedBufferSize(int rcv_buff_size);

    int getMinimumReceivedWindowBytes() const;
    void setMinimumReceiveWindowBytes(int min_rcv_win_bytes);

    bool isReuseAddress() const;
    void setIsReuseAddress(bool is_reuse_addr);
    void enableReuseAddress();
    void disableReuseAddress();

    int getMaximumSendBufferSize() const; 
    void setMaximumSendBufferSize(int max_send_buffer);

    bool isTimestampTransmitted() const;
    void setIsTimestampTransmitted(bool is_timestamp_transmitted);

    int getType() const;

};
