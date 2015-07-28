#include "socket_listen_exception.h"

#include <stdio.h>
#include <string.h>

int Network::Linux::SocketListenException::ERROR_CODE = -1;

bool Network::Linux::SocketListenException::isError(int error_code) {
  return error_code == Network::Linux::SocketListenException::ERROR_CODE;
}

const std::string Network::Linux::SocketListenException(int error_code) {
  return ::strerror(error_code);
}

Network::Linux::SocketListenException(int error_code) :
    Network::NetworkException(Network::Linux::SocketListenException(error_code)) {}
