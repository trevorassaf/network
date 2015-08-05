#include "socket_write_exception.h"

#include <cstring>
#include <cerrno>
#include <cstdio>

const int Network::Linux::SocketWriteException::ERROR_CODE = -1;

const std::string Network::Linux::SocketWriteException::getErrorString(
    int error_number 
) {
  return ::strerror(error_number);
}

bool Network::Linux::SocketWriteException::isError(int accept_error) {
  return accept_error == Network::Linux::SocketWriteException::ERROR_CODE;
}

Network::Linux::SocketWriteException::SocketWriteException() : 
    Network::NetworkException(getErrorString(errno))
{}
