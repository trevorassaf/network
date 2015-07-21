#pragma once

namespace Network {
  // Packets
  template <class Tdata> class Packet;
  template <class Tdata> class PacketWriter;
  template <class Tdata> class PacketReader;

  // Socket
  class Socket;
  class SocketConfig;
  class SocketBuilder;

};
