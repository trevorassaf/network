#include "get_address_info_error.h"

#include <string.h>
#include <string>

#include <netdb.h>

Network::GetAddrInfoError::GetAddrInfoError(int error_code) : _errorCode(error_code) {}

const char * Network::GetAddrInfoError::what() const throw() {
  return ::gai_strerror(_errorCode);
}
