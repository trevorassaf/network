#include "network.h"

#include <stdexcept>
#include <string>

class Network::Exception::BadIpv4Address : public std::exception {

  private:
    const int _errorCode;
    const std::string _badIpv4;

  public:
    BadIpv4Address(int error_code, const std::string & bad_ipv4);
    virtual const char * what() const throw(); 
};

class Network::Exception::BadPortString : public std::exception {

  private:
    const std::string _badPort;

  public:
    BadPortString(const std::string & bad_port);
    virtual const char * what() const throw(); 
};
