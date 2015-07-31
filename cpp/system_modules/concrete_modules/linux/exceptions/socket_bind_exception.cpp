#include "socket_bind_exception.h"

#include <stdio.h>
#include <string.h>

int Network::Linux::SocketBindException::ERROR_CODE = -1;

bool Network::Linux::SocketBindException::isError(int error_code) {
  return error_code == Network::Linux::SocketBindException::ERROR_CODE;
}

const std::string Network::Linux::SocketBindException::getErrorString(int error_code) {
  return ::strerror(error_code);
}

Network::Linux::SocketBindException::SocketBindException(
    int error_code
) :
    Network::NetworkException(
        Network::Linux::SocketBindException::getErrorString(
            error_code
        )
    )
{}
