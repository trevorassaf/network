#pragma once

#include <system_callers/concrete_callers/linux/exceptions/socket_initialization_exception>
#include <vector>
#include <string>

namespace Network {
  namespace Linux {
    class SocketInitializationExceptionBuilder {
      private:
        std::vector<const std::string> _errorStrings;
      public:
        SocketInitialExceptionBuilder();
        void pushErrorString(const std::string & error_string);
        const Network::Linux::SocketInitializationException build() const;
    };
  };
};
