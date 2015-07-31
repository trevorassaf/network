#include "service.h"

#include <unistd.h>

Network::Linux::Service::Service(
    unsigned int socket_descriptor
) :
    _socketDescriptor(socket_descriptor)
{}

const Network::SystemAcceptResults * Network::Linux::Service::accept() {
  return nullptr;
}

void Network::Linux::Service::close() {
  ::close(_socketDescriptor);
}
