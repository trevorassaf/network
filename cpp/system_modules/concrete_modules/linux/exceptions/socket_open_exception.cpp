#include "socket_open_exception.h"

#include <stdio.h>
#include <string.h>

int Network::Linux::SocketOpenException::ERROR_CODE = -1;

bool Network::Linux::SocketOpenException::isError(int error_code) {
  return error_code == Network::Linux::SocketOpenException::ERROR_CODE;
}

const std::string Network::Linux::SocketOpenException(int error_code) {
  return ::strerror(error_code);
}

Network::Linux::SocketOpenException(
    int error_code
) :
    Network::NetworkException(
        Network::Linux::SocketOpenException::getErrorString(error_code)
    )
{}
