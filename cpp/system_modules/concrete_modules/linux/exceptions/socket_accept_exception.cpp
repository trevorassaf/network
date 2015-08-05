#include "socket_accept_exception.h"

#include <cerrno>
#include <cstdio>
#include <cstring>

const int Network::Linux::SocketAcceptException::ERROR_CODE = -1;

const std::string Network::Linux::SocketAcceptException::getErrorString(
    int error_number 
) {
  return ::strerror(error_number);
}

bool Network::Linux::SocketAcceptException::isError(int accept_error) {
  return accept_error == Network::Linux::SocketAcceptException::ERROR_CODE;
}

Network::Linux::SocketAcceptException::SocketAcceptException() : 
    Network::NetworkException(getErrorString(errno))
{}
