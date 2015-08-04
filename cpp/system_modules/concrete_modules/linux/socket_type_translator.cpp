#include "socket_type_translator.h"

#include <sys/types.h>
#include <sys/socket.h>

const Network::Linux::SocketTypeTranslator::SocketTypeToOsCodeMap
Network::Linux::SocketTypeTranslator::SOCKET_TYPE_TO_OS_CODE_MAP = {
  {Network::Ip::SocketType::STREAM, SOCK_STREAM},
  {Network::Ip::SocketType::DATAGRAM, SOCK_DGRAM} 
};

const Network::Linux::SocketTypeTranslator::OsCodeToSocketTypeMap
Network::Linux::SocketTypeTranslator::OS_CODE_TO_SOCKET_TYPE_MAP = {
  {SOCK_STREAM, Network::Ip::SocketType::STREAM},
  {SOCK_DGRAM, Network::Ip::SocketType::DATAGRAM}
};

int Network::Linux::SocketTypeTranslator::translateToOsCode(
    Network::Ip::SocketType socket_type 
) const {
  return SOCKET_TYPE_TO_OS_CODE_MAP.at(socket_type);
}

Network::Ip::SocketType Network::Linux::SocketTypeTranslator::translateFromOsCode(
    int os_code    
) const {
  return OS_CODE_TO_SOCKET_TYPE_MAP.at(os_code);
}
