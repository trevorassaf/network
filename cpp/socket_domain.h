#include "network_namespace.h"

enum class Network::SocketDomain {
  STREAM,
  DATAGRAM,
  SEQPACKET
};
