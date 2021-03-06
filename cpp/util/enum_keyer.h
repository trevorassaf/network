#pragma once

#include <cstdlib>

namespace Network {
  struct EnumClassKeyer {
      template <typename T> std::size_t operator()(const T & t) const {
        return static_cast<std::size_t>(t);
      }
  };
};
