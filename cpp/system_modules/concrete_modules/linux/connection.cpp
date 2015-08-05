#include "connection.h"

#include <system_modules/concrete_modules/linux/exceptions/socket_close_exception.h>
#include <system_modules/concrete_modules/linux/exceptions/socket_write_exception.h>
#include <system_modules/concrete_modules/linux/exceptions/socket_read_exception.h>

#include <system_modules/abstract_modules/connection/system_read_results.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

Network::Linux::Connection::Connection(
    int socket_descriptor,
    const Network::Ip::Host & remote_host,
    const Network::Ip::Host & local_host 
) :
    _socketDescriptor(socket_descriptor),
    _remoteHost(remote_host),
    _localHost(local_host)
{}

const Network::Ip::Host &
Network::Linux::Connection::getRemoteHost() const {
  return _remoteHost;
}

const Network::Ip::Host &
Network::Linux::Connection::getLocalHost() const {
  return _localHost;
}

void Network::Linux::Connection::write(
    const Network::SystemWriteParameters & write_params    
) const {
  size_t bytes_sent = 0;
  while (bytes_sent < write_params.getBufferSize()) {
    int write_result = ::send(
        _socketDescriptor,
        write_params.getBuffer() + bytes_sent,
        write_params.getBufferSize() - bytes_sent,
        0
    );
    
    if (Network::Linux::SocketWriteException::isError(write_result)) {
      throw Network::Linux::SocketWriteException();
    }
    
    bytes_sent += write_result;
  }
}

const Network::SystemReadResults
Network::Linux::Connection::read(
    const Network::SystemReadParameters & read_parameters    
) const {
  size_t bytes_read = 0;
  uint8_t * read_buffer = new uint8_t[read_parameters.getBufferSize()];
  while (bytes_read < read_parameters.getBufferSize()) {
    int read_result = ::recv(
        _socketDescriptor,
        read_buffer,
        read_parameters.getBufferSize() - bytes_read,
        0
    );

    if (Network::Linux::SocketReadException::isError(read_result)) {
      throw Network::Linux::SocketReadException(); 
    }

    bytes_read += read_result;
  }

  return Network::SystemReadResults(
      read_buffer,
      read_parameters.getBufferSize()
  );
}

void Network::Linux::Connection::close() {
  int close_result = ::close(_socketDescriptor);
  if (Network::Linux::SocketCloseException::isError(close_result)) {
    throw Network::Linux::SocketCloseException();
  }
}
