#pragma once

#include <exceptions/network_exception.h>
#include <vector>
#include <string>

namespace Network {
  namespace Linux {
    class SocketInitializationException : public Network::NetworkException {
      private:
        const std::string serializeErrorStrings(
            const std::vector<std::string> & error_strings
        ) const; 
      public:
        SocketInitializationException(const std::vector<std::string> & error_strings);
    };
  };
};
