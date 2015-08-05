#include "socket_listen_exception.h"

#include <cstdio>
#include <cstring>

int Network::Linux::SocketListenException::ERROR_CODE = -1;

bool Network::Linux::SocketListenException::isError(int error_code) {
  return error_code == Network::Linux::SocketListenException::ERROR_CODE;
}

const std::string Network::Linux::SocketListenException::getErrorString(int error_code) {
  return ::strerror(error_code);
}

Network::Linux::SocketListenException::SocketListenException(
    int error_code
) :
    Network::NetworkException(
        Network::Linux::SocketListenException::getErrorString(error_code)
    )
{}
