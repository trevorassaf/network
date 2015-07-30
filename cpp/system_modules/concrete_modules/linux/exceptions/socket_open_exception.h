#pragma once

#include <exceptions/network_exception.h>

namespace Network {
  namespace Linux {
    class Network::Linux::SocketOpenException : public Network::NetworkException {
      private:
        static int ERROR_CODE;       
      public:
        static bool isError(int error_code);
        static const std::string getErrorString(int error_code);
        SocketOpenException(int error_code);
    };
  };
};
