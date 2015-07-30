#pragma once

#include <exceptions/network_exception.h>

namespace Network {
  namespace Linux {
    class GetAddrInfoException : public Network::NetworkException {
     
      private:
        static const int VALID_CODE;

      public:
        static bool isError(int error_number);
        GetAddrInfoException(int error_number);
    };
  };
};
