#pragma once

#include <exceptions/network_exception>
#include <vector>
#include <string>

namespace Network {
  namespace Linux {
    class Network::Linux::SocketInitializationException : public Network::NetworkException {
      private:
        const std::string serializeErrorStrings(
            const std::vector<const std::string> & error_strings
        ) const; 
      public:
        NetworkException(const std::vector<const std::string> & error_strings);
    };
  };
};
