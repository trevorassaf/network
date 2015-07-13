#pragma once

#include "network.h"
#include "socket_builder.h"
#include "socket_config.h"

#include <unordered_map>

class Network::Socket : Network::SocketConfig {

  public:
    enum class AddressFamily {
      IPV4,
      IPV6
    };

    enum class Type {
      TCP,
      UDP
    };
    
    struct EnumClassKeyer {
      template <typename T>
      std::size_t operator()(const T & t) const {
        return static_cast<std::size_t>(t);
      }
    };
    
    typedef std::unordered_map<AddressFamily, int, EnumClassKeyer> AddressFamilyMap; 
    typedef std::unordered_map<int, AddressFamily> ReverseAddressFamilyMap; 
    
    typedef std::unordered_map<Type, int, EnumClassKeyer> TypeMap; 
    typedef std::unordered_map<int, Type> ReverseTypeMap; 
    
    static const AddressFamilyMap ADDRESS_FAMILY_MAP;
    static const ReverseAddressFamilyMap REVERSE_ADDRESS_FAMILY_MAP;

    static const TypeMap TYPE_MAP;
    static const ReverseTypeMap REVERSE_TYPE_MAP;

    Socket(const Socket & socket) = delete;
    Socket(const Socket && socket) = delete;
    Socket & operator=(const Socket & socket) = delete;

    bool isAcceptor() const;
    
    unsigned int getDomain() const;
    
    unsigned int getError() const;
    
    bool isRouting() const;
    Network::SocketConfig * setIsRouting(bool is_routing) override;
    Network::SocketConfig * enableRouting() override;
    Network::SocketConfig * disableRouting() override;

    bool isKeepAlive() const;
    Network::SocketConfig * setIsKeepAlive(bool is_keep_alive) override;
    Network::SocketConfig * enableKeepAlive() override;
    Network::SocketConfig * disableKeepAlive() override;

    bool isLinger() const;
    Network::SocketConfig * setIsLinger(bool is_linger) override;
    Network::SocketConfig * enableLinger() override;
    Network::SocketConfig * disableLinger() override;

    bool isOobInline() const;
    Network::SocketConfig * setIsOobInline(bool is_oob_inline) override;
    Network::SocketConfig * enableOobInline() override;
    Network::SocketConfig * disableOobInline() override;

    bool isPassCredentials() const;
    Network::SocketConfig * setIsPassCredentials(bool is_pass_cred) override;
    Network::SocketConfig * enablePassCredentials() override;
    Network::SocketConfig * disablePassCredentials() override;

    unsigned int getPriority() const;
    Network::SocketConfig * setPriority(unsigned int priority) override;

    unsigned int getProtocol() const;

    unsigned int getReceiveBufferSize() const;
    Network::SocketConfig * setReceivedBufferSize(unsigned int rcv_buff_size) override;

    unsigned int getMinimumReceivedWindowBytes() const;
    Network::SocketConfig * setMinimumReceiveWindowBytes(unsigned int min_rcv_win_bytes) override;

    bool isReuseAddress() const;
    Network::SocketConfig * setIsReuseAddress(bool is_reuse_addr) override;
    Network::SocketConfig * enableReuseAddress() override;
    Network::SocketConfig * disableReuseAddress() override;

    unsigned int getMaximumSendBufferSize() const; 
    Network::SocketConfig * setMaximumSendBufferSize(unsigned int max_send_buffer) override;

    bool isTimestampTransmitted() const;
    Network::SocketConfig * setIsTimestampTransmitted(bool is_timestamp_transmitted) override;

    unsigned int getType() const;
  
  private:
    friend class SocketBuilder;

    unsigned int _socketDescriptor;

    Socket();
    Socket(unsigned int socket_descriptor);
};
