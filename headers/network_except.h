#include "network.h"

#include <vector>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <arpa/inet.h>

class Network::Exception::NetworkRuntimeError : public std::runtime_error {

  private:
    static const std::string composeErrorMessage(int error_number, const std::string & user_error_str);

  public:
    NetworkRuntimeError(int error_number, const std::string & error_str);
    NetworkRuntimeError(const std::string & error_str);
    NetworkRuntimeError(int error_number);
};

class Network::Exception::BadIpAddressString : public std::exception {

  private:
    const int _ipVersion;
    const std::string _badIp;

    typedef std::unordered_map<int, const std::string> ip_version_map;
    const static ip_version_map IP_VERSIONS;

  public:
    BadIpAddressString(int ip_version, const std::string & bad_ip);
    virtual const char * what() const throw(); 
};

class Network::Exception::BadPortString : public std::exception {

  private:
    const std::string _badPort;

  public:
    BadPortString(const std::string & bad_port);
    virtual const char * what() const throw(); 
};

class Network::Exception::GetAddrInfoError : public std::exception {
  private:
    const int _errorCode; 

  public:
    GetAddrInfoError(int error_code);
    virtual const char * what() const throw(); 
};

class Network::Exception::SocketError : public std::exception {

  private:
    const std::vector<int> _errorNumbers;

  public:
    SocketError(const std::vector<int> error_numbers);
    virtual const char * what() const throw(); 
};
