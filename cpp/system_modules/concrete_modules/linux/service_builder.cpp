#include "service_builder.h"
#include <system_modules/concrete_modules/linux/exceptions/getaddrinfo_exception.h>
#include <system_modules/concrete_modules/linux/exceptions/socket_initialization_exception_builder.h>
#include <system_modules/concrete_modules/linux/exceptions/socket_open_exception.h>
#include <system_modules/concrete_modules/linux/exceptions/socket_bind_exception.h>
#include <system_modules/concrete_modules/linux/exceptions/socket_listen_exception.h>
#include <system_modules/concrete_modules/linux/service.h>

#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <ifaddrs.h>

#include <cstring>

const Network::Linux::ServiceBuilder::AddressFamilyMap
Network::Linux::ServiceBuilder::ADDRESS_FAMILY_MAP = {
  {Network::Ip::AddressFamily::V4, AF_INET},
  {Network::Ip::AddressFamily::V6, AF_INET6},
  {Network::Ip::AddressFamily::UNSPECIFIED, AF_UNSPEC}
};

const Network::Linux::ServiceBuilder::SocketTypeMap
Network::Linux::ServiceBuilder::SOCKET_TYPE_MAP = {
  {Network::Ip::SocketType::STREAM, SOCK_STREAM},
  {Network::Ip::SocketType::DATAGRAM, SOCK_DGRAM}
};

int Network::Linux::ServiceBuilder::translateAddressFamilyToOsCode(Network::Ip::AddressFamily address_family) {
  return Network::Linux::ServiceBuilder::ADDRESS_FAMILY_MAP.at(address_family);
}

int Network::Linux::ServiceBuilder::translateSocketTypeToOsCode(Network::Ip::SocketType socket_type) {
  return Network::Linux::ServiceBuilder::SOCKET_TYPE_MAP.at(socket_type);
}

const Network::SystemListenResults * Network::Linux::ServiceBuilder::listen(
    const Network::SystemListenParameters * listen_params    
) {
  // Unpack parameters
  const Network::Ip::ServiceHostConfig & service_host_config = listen_params->getServiceHostConfig();
  const Network::Ip::AddressConfig & address_config = service_host_config.getAddressConfig();
  const Network::Ip::PortConfig & port_config = service_host_config.getPortConfig();
  Network::Ip::AddressFamily address_family = service_host_config.getAddressFamily();
  Network::Ip::SocketType socket_type = service_host_config.getSocketType();
  unsigned int backlog_size = service_host_config.getBacklogSize();

  struct addrinfo hints, *serv_info;
  ::memset(&hints, 0, sizeof(hints));
  hints.ai_family = translateAddressFamilyToOsCode(address_family);
  hints.ai_socktype = translateSocketTypeToOsCode(socket_type);

  // Fetch information on available addresses
  int get_addr_info_result = ::getaddrinfo(
      (address_config.hasAddress()) 
          ? address_config.getAddress().getAddressString().c_str()
          : nullptr,
      (port_config.hasPort())
          ? port_config.getPort().toString().c_str()
          : nullptr,
      &hints,
      &serv_info
  );

  // Check for getaddrinfo() error
  if (Network::Linux::GetAddrInfoException::isError(get_addr_info_result)) {
    throw Network::Linux::GetAddrInfoException(get_addr_info_result);
  }

  // Iterate through network ifaces (in 'serv_info') and stop when we successfully
  // opening listening socket
  int socket_descriptor;
  bool has_socket_descriptor = false;
  struct addrinfo * current_serv_info = serv_info;
  
  Network::Linux::SocketInitializationExceptionBuilder exception_builder;

  while (current_serv_info) {
    // Attempt to open socket
    int socket_result = ::socket(
        current_serv_info->ai_family,
        current_serv_info->ai_socktype,
        current_serv_info->ai_protocol
    );

    // Check for socket open error
    if (Network::Linux::SocketOpenException::isError(socket_result)) {
      // Register socket open error
      exception_builder.pushErrorString(
          Network::Linux::SocketOpenException::getErrorString(
              socket_result
          )
      );

      // Try to initialize next iface
      current_serv_info = current_serv_info->ai_next;
      continue;
    }

    socket_descriptor = socket_result;

    // Attempt to bind socket
    int bind_result = ::bind(
        socket_result,
        current_serv_info->ai_addr,
        current_serv_info->ai_addrlen
    );

    // Check for socket bind error
    if (Network::Linux::SocketBindException::isError(bind_result)) {
      // Close opened socket
      ::close(socket_descriptor);

      // Register socket bind error
      exception_builder.pushErrorString(
          Network::Linux::SocketBindException::getErrorString(
              socket_result
          )
      );

      // Try to initialize next iface
      current_serv_info = current_serv_info->ai_next;
      continue;
    }

    // Attempt to listen
    int listen_result = ::listen(
        socket_descriptor,
        backlog_size
    );

    // Check for socket listen error
    if (Network::Linux::SocketListenException::isError(listen_result)) {
      // Close bound socket
      ::close(socket_descriptor);

      // Register socket listen error
      exception_builder.pushErrorString(
          Network::Linux::SocketListenException::getErrorString(
              socket_result
          )
      );

      // Try to initialize next iface
      current_serv_info = current_serv_info->ai_next;
      continue;
    }

    has_socket_descriptor = true;
    ::freeaddrinfo(serv_info);
    break;
  }

  Network::Ip::PortBuilder port_builder;

  switch (current_serv_info->ai_addr->sa_family) {
    case AF_INET:
      {
        sockaddr_in * ipv4_socket_address = 
            reinterpret_cast<sockaddr_in *>(current_serv_info->ai_addr);
        port_builder.setNetworkByteOrderPortNumber(ipv4_socket_address->sin_port);
        break;
      }
    case AF_INET6:
      {
        sockaddr_in6 * ipv6_socket_address = 
            reinterpret_cast<sockaddr_in6 *>(current_serv_info->ai_addr);
        port_builder.setNetworkByteOrderPortNumber(ipv6_socket_address->sin6_port);
        break;
      }
    default:
      throw std::runtime_error("Unknown address family!");
      break;
  }

  // Throw service-builder exception because we failed to initialize service-builder socket
  if (!has_socket_descriptor) {
    throw exception_builder.build(); 
  }

  Network::SystemServiceModule::ListeningHosts listening_hosts;
  Network::Ip::AddressBuilder address_builder;

  if (address_config.hasAddress()) {
    listening_hosts.push_back(
        Network::Ip::Host(
            address_config.getAddress(),
            port_builder.build()
        )    
    ); 
  } else {
    ifaddrs * interface_address_head;
    ::getifaddrs(&interface_address_head);
    ifaddrs * interface_address = interface_address_head;

    while (interface_address) {
      switch (interface_address->ifa_addr->sa_family) {
        case AF_INET:
          {
            sockaddr_in * ipv4_address =
                reinterpret_cast<sockaddr_in *>(
                    interface_address->ifa_addr
                );
            
            char ipv4_address_str[INET_ADDRSTRLEN+1];
            ::bzero(ipv4_address_str, INET_ADDRSTRLEN+1);
            ::inet_ntop(
                AF_INET,
                &ipv4_address->sin_addr,
                ipv4_address_str,
                INET_ADDRSTRLEN
            );

            listening_hosts.push_back(
                Network::Ip::Host(
                    Network::Ip::Address(ipv4_address_str),
                    Network::Ip::Port(port_builder.build())
                )
            );
            break;
          }
        case AF_INET6:
          {
            sockaddr_in6 * ipv6_address =
                reinterpret_cast<sockaddr_in6 *>(
                    interface_address->ifa_addr
                );
            
            char ipv6_address_str[INET6_ADDRSTRLEN+1];
            ::bzero(ipv6_address_str, INET6_ADDRSTRLEN+1);
            ::inet_ntop(
                AF_INET6,
                &ipv6_address->sin6_addr,
                ipv6_address_str,
                INET6_ADDRSTRLEN
            );

            listening_hosts.push_back(
                Network::Ip::Host(
                    Network::Ip::Address(ipv6_address_str),
                    Network::Ip::Port(port_builder.build())
                )
            );
            break;
          }
        default:
          throw std::runtime_error("Invalid AddressFamily!");
          break;
      }

      interface_address = interface_address->ifa_next;
    }

    ::freeifaddrs(interface_address_head);
  }

  // Caller requires linux-specific service-module in order to assemble a service
  return new Network::SystemListenResults(
      new Network::Linux::Service(
          socket_descriptor,
          listening_hosts
      )
  );
}
