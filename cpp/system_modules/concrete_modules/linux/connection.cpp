#include "connection.h"

#include <ip/port_builder.h>
#include <ip/address_builder.h>

#include <system_modules/concrete_modules/linux/exceptions/socket_close_exception.h>
#include <system_modules/concrete_modules/linux/exceptions/socket_write_exception.h>
#include <system_modules/concrete_modules/linux/exceptions/socket_read_exception.h>
#include <system_modules/concrete_modules/linux/exceptions/get_sock_name_exception.h>
#include <system_modules/concrete_modules/linux/exceptions/get_peer_name_exception.h>

#include <system_modules/abstract_modules/connection/system_read_results.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

#include <cstring>
#include <string>

Network::Ip::Host Network::Linux::Connection::generateLocalHost(
    int socket_descriptor
) const {
  sockaddr_storage socket_storage;
  socklen_t socket_storage_len = sizeof(socket_storage);
  int getsockname_result = ::getsockname(
      socket_descriptor,
      reinterpret_cast<sockaddr *>(&socket_storage),
      &socket_storage_len
  );

  if (Network::Linux::GetSockNameException::isError(getsockname_result)) {
    throw Network::Linux::GetSockNameException();
  }

  return deriveHost(socket_storage);
}

Network::Ip::Host Network::Linux::Connection::generateRemoteHost(
    int socket_descriptor
) const {
  sockaddr_storage socket_storage;
  socklen_t socket_storage_len = sizeof(socket_storage);

  int getpeername_result = ::getpeername(
      socket_descriptor,
      reinterpret_cast<sockaddr *>(&socket_storage),
      &socket_storage_len
  );

  if (Network::Linux::GetPeerNameException::isError(getpeername_result)) {
    throw Network::Linux::GetPeerNameException();
  }

  return deriveHost(socket_storage);
}

Network::Ip::Host Network::Linux::Connection::deriveHost(
    const sockaddr_storage & socket_storage    
) const {
  
  Network::Ip::PortBuilder port_builder;
  Network::Ip::AddressBuilder address_builder;
  
  switch (socket_storage.ss_family) {
    case AF_INET:
      {
        const sockaddr_in * ipv4_socket_address = 
            reinterpret_cast<const sockaddr_in *>(&socket_storage);
        port_builder.setNetworkByteOrderPortNumber(
            ipv4_socket_address->sin_port
        );
        
        char ipv4_str[INET_ADDRSTRLEN+1];
        ::bzero(ipv4_str, INET_ADDRSTRLEN+1);
        ::inet_ntop(
            AF_INET,
            &ipv4_socket_address->sin_addr,
            ipv4_str,
            INET_ADDRSTRLEN
        );

        address_builder.setAddressString(ipv4_str);
        break;
      }
    case AF_INET6:
      {
        const sockaddr_in6 * ipv6_socket_address = 
            reinterpret_cast<const sockaddr_in6 *>(&socket_storage);
        port_builder.setNetworkByteOrderPortNumber(
            ipv6_socket_address->sin6_port
        );
        
        char ipv6_str[INET6_ADDRSTRLEN+1];
        ::bzero(ipv6_str, INET6_ADDRSTRLEN+1);
        ::inet_ntop(
            AF_INET6,
            &ipv6_socket_address->sin6_addr,
            ipv6_str,
            INET6_ADDRSTRLEN
        );

        address_builder.setAddressString(ipv6_str);
        break;
      }
    default:
      throw std::runtime_error("Unknown address family!");
      break;
  }

  return Network::Ip::Host(
      address_builder.build(),
      port_builder.build()
  );
}

Network::Linux::Connection::Connection(
    int socket_descriptor
) :
    _socketDescriptor(socket_descriptor),
    _remoteHost(generateRemoteHost(socket_descriptor)),
    _localHost(generateLocalHost(socket_descriptor))
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
  if (_isOpen) {
    ::close(_socketDescriptor);
    _isOpen = false;
  }
}

Network::Linux::Connection::~Connection() {
  this->close();
}
