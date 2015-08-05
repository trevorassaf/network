#include "get_peer_name_exception.h"

#include <cstring>
#include <cerrno>
#include <cstdio>

const int Network::Linux::GetPeerNameException::ERROR_CODE = -1;

const std::string Network::Linux::GetPeerNameException::getErrorString(
    int error_number 
) {
  return ::strerror(error_number);
}

bool Network::Linux::GetPeerNameException::isError(int accept_error) {
  return accept_error == Network::Linux::GetPeerNameException::ERROR_CODE;
}

Network::Linux::GetPeerNameException::GetPeerNameException() : 
    Network::NetworkException(getErrorString(errno))
{}
