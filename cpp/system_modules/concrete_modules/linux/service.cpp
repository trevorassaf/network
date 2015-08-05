#include "service.h"

#include <ip/port.h>
#include <ip/port_builder.h>

#include <system_modules/concrete_modules/linux/exceptions/get_sock_name_exception.h>
#include <system_modules/concrete_modules/linux/exceptions/socket_accept_exception.h>
#include <system_modules/abstract_modules/service/system_accept_results.h>
#include <system_modules/abstract_modules/service/system_accept_results_builder.h>

#include <stdexcept>
#include <string>
#include <cstring>

#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>

#include <iostream>

const Network::Linux::Service::OsAddressFamilyMap
Network::Linux::Service::OS_ADDRESS_FAMILY_MAP = {
  {AF_INET, Network::Ip::AddressFamily::V4},
  {AF_INET6, Network::Ip::AddressFamily::V6}
};

Network::Ip::AddressFamily
Network::Linux::Service::translateOsCodeToAddressFamily(
    int os_code
) {
  return Network::Linux::Service::OS_ADDRESS_FAMILY_MAP.at(os_code);  
}

const Network::Linux::Service::OsSocketTypeMap
Network::Linux::Service::OS_SOCKET_TYPE_MAP = {
  {SOCK_STREAM, Network::Ip::SocketType::STREAM},
  {SOCK_DGRAM, Network::Ip::SocketType::DATAGRAM}
};

Network::Ip::SocketType
Network::Linux::Service::translateOsCodeToSocketType(
    int os_code
) {
  return Network::Linux::Service::OS_SOCKET_TYPE_MAP.at(os_code);  
}

const Network::Ip::Host Network::Linux::Service::generateIpv6Host(
    const sockaddr_in6 & ipv6_address
) const {
    char ipv6_cstring[INET6_ADDRSTRLEN+1];
    ::bzero(ipv6_cstring, INET6_ADDRSTRLEN+1);
   
    ::inet_ntop(
        AF_INET6,
        &ipv6_address.sin6_addr,
        ipv6_cstring,
        INET6_ADDRSTRLEN
    );
    
    const Network::Ip::Address address(ipv6_cstring);
    
    const Network::Ip::Port port = Network::Ip::PortBuilder()
        .setNetworkByteOrderPortNumber(ipv6_address.sin6_port)
        .build();

    return Network::Ip::Host(address, port);
}

const Network::Ip::Host Network::Linux::Service::generateIpv4Host(
    const sockaddr_in & ipv4_address
) const {
    char ipv4_cstring[INET_ADDRSTRLEN+1];
    ::bzero(ipv4_cstring, INET_ADDRSTRLEN+1);
    
    ::inet_ntop(
        AF_INET,
        &ipv4_address.sin_addr,
        ipv4_cstring,
        INET_ADDRSTRLEN
    );

    const Network::Ip::Address address(ipv4_cstring);
    
    const Network::Ip::Port port = Network::Ip::PortBuilder()
        .setNetworkByteOrderPortNumber(ipv4_address.sin_port)
        .build();

    return Network::Ip::Host(address, port);
}

const Network::Ip::Host Network::Linux::Service::generateLocalHost() const {
  sockaddr_storage socket_address;
  socklen_t socket_address_length = sizeof(socket_address);
  int getsockname_result = ::getsockname(
      _socketDescriptor,
      reinterpret_cast<sockaddr *>(&socket_address),
      &socket_address_length
  );   

  if (Network::Linux::GetSockNameException::isError(getsockname_result)) {
    throw Network::Linux::GetSockNameException();
  }

  int os_address_family_code = socket_address.ss_family;
  Network::Ip::AddressFamily address_family = translateOsCodeToAddressFamily(os_address_family_code);

  switch (address_family) {
    case Network::Ip::AddressFamily::V4:
      {
        const sockaddr_in * ipv4_socket_address =
            reinterpret_cast<sockaddr_in *>(&socket_address);
        return generateIpv4Host(*ipv4_socket_address); 
      }
    case Network::Ip::AddressFamily::V6:
      {
        const sockaddr_in6 * ipv6_socket_address =
            reinterpret_cast<sockaddr_in6 *>(&socket_address);
        return generateIpv6Host(*ipv6_socket_address); 
      }
    default:
      std::cout << "Invalid address family (service): " << socket_address.ss_family 
          << std::endl;
      throw std::runtime_error("Invalid AddressFamily!");
      break;
  }
}

Network::Linux::Service::Service(
    unsigned int socket_descriptor,
    const Network::SystemServiceModule::ListeningHosts & listening_hosts
) :
    _socketDescriptor(socket_descriptor),
    _listeningHosts(listening_hosts)
{}

const Network::SystemAcceptResults * Network::Linux::Service::accept() {
  sockaddr_storage socket_storage;
  socklen_t socket_storage_length = sizeof(socket_storage);

  std::cout << "Calling accept!" << std::endl;

  int accept_result = ::accept(
      _socketDescriptor,
      reinterpret_cast<sockaddr *>(&socket_storage),
      &socket_storage_length
  );
  
  std::cout << "After accept!" << std::endl;

  if (Network::Linux::SocketAcceptException::isError(accept_result)) {
    throw Network::Linux::SocketAcceptException();   
  }

  Network::SystemAcceptResultsBuilder accept_results_builder;
 
  int os_address_family = socket_storage.ss_family;

  Network::Ip::AddressFamily address_family =
      translateOsCodeToAddressFamily(os_address_family);

  accept_results_builder.setAddressFamily(address_family);
 
  switch (address_family) {
    case Network::Ip::AddressFamily::V4:
    {
      const sockaddr_in * ipv4_socket_address =
          reinterpret_cast<sockaddr_in *>(&socket_storage);
      accept_results_builder.setRemoteHost(
          generateIpv4Host(*ipv4_socket_address)
      );
      break; 
    }
    case Network::Ip::AddressFamily::V6:
    {
      const sockaddr_in6 * ipv6_socket_address =
          reinterpret_cast<sockaddr_in6 *>(&socket_storage);
      accept_results_builder.setRemoteHost(
          generateIpv6Host(*ipv6_socket_address)
      );
      break; 
    }
    default:
      throw std::runtime_error("Unexpected address family!");
      break;
  }

  return accept_results_builder.build();
}

const Network::SystemServiceModule::ListeningHosts &
Network::Linux::Service::getListeningHosts() const {
  return _listeningHosts;
}

void Network::Linux::Service::close() {
  ::close(_socketDescriptor);
}
