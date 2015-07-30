#include "service_builder.h"
#include <system_modules/concrete_modules/linux/exceptions/getaddrinfo_exception.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#include <cstring>

Network::Linux::ServiceBuilder::AddressFamilyMap
Network::Linux::ServiceBuilder::ADDRESS_FAMILY_MAP = {
  {Network::Ip::AddressFamily::V4, AF_INET},
  {Network::Ip::AddressFamily::V6, AF_INET6},
  {Network::Ip::AddressFamily::UNSPECIFIED, AF_UNSPEC}
};

Network::Linux::ServiceBuilder::SocketTypeMap
Network::Linux::ServiceBuilder::SOCKET_TYPE_MAP = {
  {Network::Ip::SocketType::STREAM, SOCK_STREAM},
  {Network::Ip::SocketType::DATAGRAM, SOCK_DGRAM}
};

static int Network::Linux::ServiceBuilder::translateAddressFamilyToOsCode(Network::Ip::AddressFamily address_family) {
  return Network::Linux::ServiceBuilder::ADDRESS_FAMILY_MAP.at(address_family);
}

static int Network::Linux::ServiceBuilder::translateForOsCode(Network::Ip::SocketType socket_type) {
  return Network::Linux::ServiceBuilder::SOCKET_TYPE_MAP.at(socket_type);
}

const Network::SystemListenResults * Network::Linux::ServiceBuilder::listen(
    const Network::SystemListenParameters * listen_params    
) {
  // Unpack parameters
  const Network::Ip::ServiceHostConfig & service_host_config = listen_params
      ->getServiceHostConfig();
  const Network::Ip::AddressConfig & address_config = service_host_config
      .getAddressConfig();
  const Network::Ip::PortConfig & port_config = service_host_config
      .getPortConfig();

  Network::Ip::AddressFamily address_family = address_config.getAddressFamily();
  Network::Ip::SocketType socket_type = address_config.getSocketType();

  struct addrinfo hints, *serv_info;
  ::memset(&hints, 0, sizeof(hints));
  hints.ai_family = translateAddressFamily(address_family);
  hints.ai_socktype = translateSocketType(socket_type);

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
    break;
  }

  // Throw service-builder exception because we failed to initialize service-builder socket
  if (!has_socket_descriptor) {
    throw exception_builder.build(); 
  }

  // Caller requires linux-specific service-module in order to assemble a service
  return new Network::ServiceListenResults(
      new Network::Linux::ServiceModule(socket_descriptor)    
  );
}
