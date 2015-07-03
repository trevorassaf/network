#pragma once

namespace Network {
  class Ipv4;
  class Ipv6;
  class Port;
  class Host;
  class Socket;
  
  // Exceptions
  namespace Exception {
    class NetworkRuntimeError;
    class BadIpAddressString;
    class BadPortString;
  };
};

//#define NET_ASSERT(error_code) (if (error_code == -1) { ::perror(error_code); ::exit(1); })
