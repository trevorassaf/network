#include "socket_read_exception.h"

#include <cstring>
#include <cerrno>
#include <cstdio>

const int Network::Linux::SocketReadException::ERROR_CODE = -1;

const std::string Network::Linux::SocketReadException::getErrorString(
    int error_number 
) {
  return ::strerror(error_number);
}

bool Network::Linux::SocketReadException::isError(int accept_error) {
  return accept_error == Network::Linux::SocketReadException::ERROR_CODE;
}

Network::Linux::SocketReadException::SocketReadException() : 
    Network::NetworkException(getErrorString(errno))
{}
