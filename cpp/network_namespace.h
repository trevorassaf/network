#pragma once

namespace Network {
  // Exceptions
  class NetworkRuntimeError;
  class IpAddressStringError;
  class PortStringError;
  class GetAddrInfoError;
  class SocketError;

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
};
