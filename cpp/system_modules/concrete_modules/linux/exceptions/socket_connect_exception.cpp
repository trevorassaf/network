#include "socket_connect_exception.h"

#include <cstring>
#include <cerrno>
#include <cstdio>

const int Network::Linux::SocketConnectException::ERROR_CODE = -1;

const std::string Network::Linux::SocketConnectException::getErrorString(
    int error_number 
) {
  return ::strerror(error_number);
}

bool Network::Linux::SocketConnectException::isError(int accept_error) {
  return accept_error == Network::Linux::SocketConnectException::ERROR_CODE;
}

Network::Linux::SocketConnectException::SocketConnectException() : 
    Network::NetworkException(getErrorString(errno))
{}
