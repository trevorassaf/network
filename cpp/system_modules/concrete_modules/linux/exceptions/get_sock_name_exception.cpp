#include "get_sock_name_exception.h"

#include <errno.h>
#include <stdio.h>

const int Network::Linux::GetSockNameException::ERROR_CODE = -1;

const std::string Network::Linux::GetSockNameException::getErrorString(
    int error_number 
) {
  return ::strerror(error_number);
}

bool Network::Linux::GetSockNameException::isError(int accept_error) {
  return accept_error == Network::Linux::GetSockNameException::ERROR_CODE;
}

Network::Linux::GetSockNameException::GetSockNameException() : 
    Network::NetworkException(getErrorString(errno))
{}
