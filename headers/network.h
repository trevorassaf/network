#pragma once

namespace Network {
  class Ipv4;
  class Ipv6;
  class Port;
  class Host;
  template <class Tdata> class Packet;
  template <class Tdata> class PacketWriter;
  template <class Tdata> class PacketReader;

  class Socket;
  class SocketConfig;
  class SocketBuilder;

  namespace Ip {
    class Config;
    class Connection;

    namespace Tcp {
      class Config;
      class ConnectionBuilder;
      class Connection;
      class Service;
      class ServiceBuilder;
    };

    namespace Udp {
      class Config;
      class RequestBuilder;
      class Request;
      class Service;
      class ServiceBuilder;
    };
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
