#include "socket_close_exception.h"

#include <cstring>
#include <cerrno>
#include <cstdio>

const int Network::Linux::SocketCloseException::ERROR_CODE = -1;

const std::string Network::Linux::SocketCloseException::getErrorString(
    int error_number 
) {
  return ::strerror(error_number);
}

bool Network::Linux::SocketCloseException::isError(int accept_error) {
  return accept_error == Network::Linux::SocketCloseException::ERROR_CODE;
}

Network::Linux::SocketCloseException::SocketCloseException() : 
    Network::NetworkException(getErrorString(errno))
{}
