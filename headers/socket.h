#pragma once

#include "network.h"
#include "socket_builder.h"
#include "socket_config.h"

#include <unordered_map>

class Network::Socket : Network::SocketConfig {

  public:
    struct EnumClassKeyer {
      template <typename T>
      std::size_t operator()(const T & t) const {
        return static_cast<std::size_t>(t);
      }
    };

    enum class Option {
      DOMAIN,
      ERROR,
      BIND_TO_DEVICE,
      IS_ACCEPTOR,
      IS_ROUTING,
      IS_KEEP_ALIVE,
      IS_LINGER,
      IS_OOB_INLINE,
      IS_PASS_CREDENTIALS,
      IS_REUSE_ADDRESS,
      // IS_REUSE_PORT
      IS_TIMESTAMP_TRANSMITTED,
      PRIORITY,
      PROTOCOL,
      MAXIMUM_RECEIVED_BUFFER_BYTES,
      MINIMUM_RECEIVED_BUFFER_BYTES,
      MAXIMUM_SEND_BUFFER_BYTES,
      MINIMUM_SEND_BUFFER_BYTES,
      RECEIVE_TIMEOUT,
      SEND_TIMEOUT,
      TYPE
    };

    typedef std::unordered_map<Option, int, EnumClassKeyer> OsSocketOptionMap;
    typedef std::unordered_map<int, Option> ReverseOsSocketOptionMap;

    static const OsSocketOptionMap OPTION_MAP;
    static const ReverseOsSocketOptionMap REVERSE_OPTION_MAP;
    
    enum class Level {
      SOCKET,
      IPV4,
      IPV6,
      TCP,
      UDP
    };

    typedef std::unordered_map<Level, int, EnumClassKeyer> OsSocketLevelMap;
    typedef std::unordered_map<int, Level> ReverseOsSocketLevelMap;

    static const OsSocketLevelMap LEVEL_MAP;
    static const ReverseOsSocketLevelMap REVERSE_LEVEL_MAP;

    enum class AddressFamily {
      IPV4,
      IPV6
    };
    
    typedef std::unordered_map<AddressFamily, int, EnumClassKeyer> OsSocketAddressFamilyMap; 
    typedef std::unordered_map<int, AddressFamily> ReverseOsSocketAddressFamilyMap; 
    
    static const OsSocketAddressFamilyMap ADDRESS_FAMILY_MAP;
    static const ReverseOsSocketAddressFamilyMap REVERSE_ADDRESS_FAMILY_MAP;

    enum class Type {
      TCP,
      UDP,
      IP
      // SEQ_PACKET,
      // RDM
    };
    
    typedef std::unordered_map<Type, int, EnumClassKeyer> TypeMap; 
    typedef std::unordered_map<int, Type> ReverseTypeMap; 
    
    static const TypeMap TYPE_MAP;
    static const ReverseTypeMap REVERSE_TYPE_MAP;

    ~Socket();

    Socket(const Socket & socket) = delete;
    Socket(const Socket && socket) = delete;
    Socket & operator=(const Socket & socket) = delete;

    bool isAcceptor() const;
    
    AddressFamily getAddressFamily() const;
    
    int getError() const;

    bool isBoundToDevice() const;
    Network::SocketConfig * bindToDevice(const std::string & device_name) override;
    
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

    Type getType() const;

  private:
    friend class SocketBuilder;

    unsigned int _socketDescriptor;

    Socket();
    Socket(unsigned int socket_descriptor);
    
    template <typename T> T getOption(Option option) const;
    
    template <typename T> void setOption(Option option, const T & t) const;

    static const Level LEVEL;

    void close() const;
};
