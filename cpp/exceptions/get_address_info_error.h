#pragma once

#include "exceptions_namespace.h"

#include <vector>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <arpa/inet.h>

class Network::GetAddrInfoError : public std::exception {
  private:
    const int _errorCode; 

  public:
    GetAddrInfoError(int error_code);
    virtual const char * what() const throw(); 
};
