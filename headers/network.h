#pragma once

namespace Network {
  class Ipv4;
  class Ipv6;
  class Port;
  class Host;
  class ClientConfig;
  class ServerConfig;
  class ServerConfigBuilder;
  template <class Tdata> class Packet;
  template <class Tdata> class PacketWriter;
  template <class Tdata> class PacketReader;
  
  namespace Tcp {
    class Socket;
  };
  
  // Exceptions
  namespace Exception {
    class NetworkRuntimeError;
    class BadIpAddressString;
    class BadPortString;
    class GetAddrInfoError;
    class SocketError;
  };
};

//#define NET_ASSERT(error_code) (if (error_code == -1) { ::perror(error_code); ::exit(1); })
