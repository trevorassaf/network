#pragma once

#include "exceptions_namespace.h"

#include <stdexcept>
#include <string>
#include <unordered_map>
#include <arpa/inet.h>

class Network::PortStringError : public std::exception {

  private:
    const std::string _badPort;

  public:
    PortStringError(const std::string & bad_port);
    virtual const char * what() const throw(); 
};
