#pragma once

#include <system_modules/concrete_modules/linux/exceptions/socket_initialization_exception.h>
#include <vector>
#include <string>

namespace Network {
  namespace Linux {
    class SocketInitializationExceptionBuilder {
      
      private:
        std::vector<std::string> _errorStrings;
      
      public:
        SocketInitializationExceptionBuilder();
        void pushErrorString(const std::string & error_string);
        Network::Linux::SocketInitializationException build() const;
    };
  };
};
