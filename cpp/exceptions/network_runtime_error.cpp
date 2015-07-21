#include "network_runtime_error.h"

#include <string.h>
#include <string>

#include <netdb.h>

const std::string Network::NetworkRuntimeError::composeErrorMessage(
    int error_number,
    const std::string & user_error_str
) {
  return std::string("[user error message") 
      + user_error_str
      + std::string(", system error message: ")
      + ::strerror(error_number)
      + std::string("]");
}

Network::NetworkRuntimeError::NetworkRuntimeError(
    int error_number,
    const std::string & error_str
) : 
    std::runtime_error(
        Network::NetworkRuntimeError::composeErrorMessage(
            error_number,
            error_str
        )
    )
{}

Network::NetworkRuntimeError::NetworkRuntimeError(
    const std::string & error_str
) : 
    std::runtime_error(error_str)
{}

Network::NetworkRuntimeError::NetworkRuntimeError(
    int error_number
) : 
    std::runtime_error(::strerror(error_number))
{}
