#pragma once

#include "exceptions_namespace.h"

#include <stdexcept>
#include <string>
#include <unordered_map>
#include <arpa/inet.h>

class Network::IpAddressStringError : public std::exception { 
  private:
    const int _ipVersion;
    const std::string _badIp;

    typedef std::unordered_map<int, const std::string> ip_version_map;
    const static ip_version_map IP_VERSIONS;

  public:
    IpAddressStringError(int ip_version, const std::string & bad_ip);
    virtual const char * what() const throw(); 
};
