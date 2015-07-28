#include "getaddrinfo_exception.h"

#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

const int Network::Linux::GetAddrInfoException::VALID_VALUE = 0;

bool Network::Linux::GetAddrInfoException::isError(int error_code) {
  return error_code != VALID_CODE;
}

Network::Linux::GetAddrInfoException::GetAddrInfoException(int error_number) : 
    ::gai_strerror(error_number) {}
