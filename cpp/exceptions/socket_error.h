#pragma once

#include "exceptions_namespace.h"

#include <vector>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <arpa/inet.h>

class Network::SocketError : public std::exception {

  private:
    const std::string _errorMessage;
    const std::vector<int> _errorNumbers;

  public:
    SocketError(
        const std::string & error_message,
        const std::vector<int> error_numbers
    );
    virtual const char * what() const throw(); 
};
