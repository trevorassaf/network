#pragma once

#include "../network_namespace.h"
#include "socket_config.h"
#include "socket_builder.h"

#include <unordered_map>

class Network::Socket : Network::SocketConfig {

  public:
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

    ~Socket();

    Socket(const Socket & socket) = delete;
    Socket(const Socket && socket) = delete;
    Socket & operator=(const Socket & socket) = delete;

    bool isAcceptor() const;
    
    Network::SocketConfig::AddressFamily getAddressFamily() const;
    
    int getError() const;

    bool isBoundToDevice() const;
    const std::string getBoundDevice() const;
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
    unsigned int getPriority() const;

    Network::SocketConfig * setMaximumReceiveBufferBytes(unsigned int rcv_buff_size) override;
    unsigned int getMaximumReceiveBufferBytes() const;

    Network::SocketConfig * setMinimumReceiveBufferBytes(unsigned int min_rcv_win_bytes) override;
    unsigned int getMinimumReceiveBufferBytes() const;

    Network::SocketConfig * setMaximumSendBufferBytes(unsigned int max_send_buffer) override;
    unsigned int getMaximumSendBufferBytes() const;

    Network::SocketConfig * setMinimumSendBufferBytes(unsigned int max_send_buffer) override;
    unsigned int getMinimumSendBufferBytes() const;

    Network::SocketConfig * setReceiveTimeout(const Network::Time & time) override;
    const Network::Time getReceiveTimeout() const;

    Network::SocketConfig * setSendTimeout(const Network::Time & time) override;
    const Network::Time getSendTimeout() const;

    Network::SocketConfig::Type getType() const;

  private:
    static const Level LEVEL;

    unsigned int _socketDescriptor;

    friend class SocketBuilder;

    Socket(unsigned int socket_descriptor);
    
    template <typename T> T getOption(Option option) const;
    const std::string getOption(Option option) const;
    
    template <typename T> void setOption(Option option, const T & t) const;
    void setOption(Option option, const std::string & option_value) const;

    void close() const;
};
