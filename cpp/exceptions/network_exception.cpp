#include "network_exception.h"

Network::NetworkException::NetworkException(
    const std::string & error_message
) :
    std::runtime_error(error_message)
{}
