#pragma once

#include <exceptions/network_exception.h>

namespace Network {
  namespace Linux {
    class SocketConnectException : public Network::NetworkException {
      private:
        static const int ERROR_CODE;

      public:
        static const std::string getErrorString(int error_number);
        static bool isError(int accept_error);
        SocketConnectException();
       
    };
  };
};
