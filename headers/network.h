#pragma once

namespace Network {
  class Port;
  class PortBuilder;
  class Host;

  template <class Tdata> class Packet;
  template <class Tdata> class PacketWriter;
  template <class Tdata> class PacketReader;

  class Socket;
  class SocketConfig;
  class SocketBuilder;

  class TimeBuilder;
  class Time;

  namespace Ip {
    class IpAddress;
    class Ipv4Address;
    class Ipv6Address;


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
