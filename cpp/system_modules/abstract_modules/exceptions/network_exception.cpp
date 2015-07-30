#include "network_exception.h"

Network::NetworkException::NetworkException(
    const std::string & error_string
) : 
  std::runtime_error(error_string)
{}
