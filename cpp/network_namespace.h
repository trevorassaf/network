#pragma once

namespace Network {
  // Exceptions
  class NetworkRuntimeError;
  class IpAddressStringError;
  class PortStringError;
  class GetAddrInfoError;
  class SocketError;

  // Packets
  template <class Tdata> class Packet;
  template <class Tdata> class PacketWriter;
  template <class Tdata> class PacketReader;
  

  // Socket
  class Socket;
  class SocketConfig;
  class SocketBuilder;

};
