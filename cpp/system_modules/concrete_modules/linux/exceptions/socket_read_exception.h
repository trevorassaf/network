#pragma once

#include <exceptions/network_exception.h>

#include <string>

namespace Network {
  
  namespace Linux {

    class SocketReadException : public Network::NetworkException {
      private:
        static const int ERROR_CODE;
        const std::string getErrorString(int error_number);

      public:
        static bool isError(int accept_error);
        SocketReadException();
    };
  };
};
