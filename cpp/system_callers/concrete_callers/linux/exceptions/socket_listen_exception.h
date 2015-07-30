#pragma once

#include <exceptions/network_exception.h>

namespace Network {
  namespace Linux {
    class SocketListenException : public Network::NetworkException {
      private:
        static int ERROR_CODE;
      public:
        static bool isError(int error_code);
        static const std::string getErrorString(int error_code);
        SocketListenException(int error_code);
    };
  };
};
