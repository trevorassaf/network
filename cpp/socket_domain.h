#include <network_namespace>

enum class Network::SocketDomain {
  STREAM,
  DATAGRAM,
  SEQPACKET
};
