#pragma once

#include <exceptions/network_exception.h>

namespace Network {
  namespace Linux {
    class SocketBindException : public Network::NetworkException {
      private:
        static int ERROR_CODE;
      public:
        static bool isError(int error_code);
        static const std::string getErrorString(int error_code);
        SocketBindException(int error_code);
    };
  };
};
