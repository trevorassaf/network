#pragma once

#include <stdexcept>
#include <string>

namespace Network {
  class NetworkException : std::runtime_error {
    public:
      NetworkException(const std::string & error_message);
  };
};
