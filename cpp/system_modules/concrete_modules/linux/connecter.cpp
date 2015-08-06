#include "connecter.h"

#include <ip/port_builder.h>
#include <ip/port.h>
#include <ip/host.h>
#include <ip/address.h>
#include <ip/address_builder.h>

#include <system_modules/concrete_modules/linux/address_family_translator.h>
#include <system_modules/concrete_modules/linux/socket_type_translator.h>
#include <system_modules/concrete_modules/linux/exceptions/getaddrinfo_exception.h>
#include <system_modules/concrete_modules/linux/exceptions/socket_initialization_exception_builder.h>
#include <system_modules/concrete_modules/linux/exceptions/socket_initialization_exception.h>
#include <system_modules/concrete_modules/linux/exceptions/socket_open_exception.h>
#include <system_modules/concrete_modules/linux/exceptions/socket_bind_exception.h>
#include <system_modules/concrete_modules/linux/exceptions/socket_listen_exception.h>
#include <system_modules/concrete_modules/linux/exceptions/socket_connect_exception.h>
#include <system_modules/concrete_modules/linux/exceptions/get_sock_name_exception.h>
#include <system_modules/concrete_modules/linux/exceptions/get_peer_name_exception.h>

#include <system_modules/concrete_modules/linux/connection.h>

#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <ifaddrs.h>

#include <cerrno>
#include <cstring>

void Network::Linux::Connecter::bindLocalHostConfig(
    int socket_descriptor,
    const Network::Ip::ConnecterHostConfig & connecter_host_config
) {
  struct addrinfo hints, *serv_info;
  ::memset(&hints, 0, sizeof(hints));

  Network::Linux::AddressFamilyTranslator address_family_translator;
  hints.ai_family = address_family_translator
      .translateToOsCode(connecter_host_config.getAddressFamily());

  Network::Linux::SocketTypeTranslator socket_type_translator;
  hints.ai_socktype = socket_type_translator
      .translateToOsCode(connecter_host_config.getSocketType());

  hints.ai_flags = AI_PASSIVE;

  const Network::Ip::AddressConfig & address_config = connecter_host_config
      .getAddressConfig();
  const Network::Ip::PortConfig & port_config = connecter_host_config
      .getPortConfig();

  // Fetch information on available addresses
  int get_addr_info_result = ::getaddrinfo(
      (address_config.hasAddress()) 
          ? address_config.getAddress().getAddressString().c_str()
          : nullptr,
      (port_config.hasPort())
          ? port_config.getPort().toString().c_str()
          : "0",
      &hints,
      &serv_info
  );
  
  // Check for getaddrinfo() error
  if (Network::Linux::GetAddrInfoException::isError(get_addr_info_result)) {
    throw Network::Linux::GetAddrInfoException(get_addr_info_result);
  }

  // Iterate through candidate local addresses until we find one to bind
  struct addrinfo * current_serv_info = serv_info;

  Network::Linux::SocketInitializationExceptionBuilder exception_builder;

  while (current_serv_info) {
    // Attempt to bind socket
    int bind_result = ::bind(
        socket_descriptor,
        current_serv_info->ai_addr,
        current_serv_info->ai_addrlen
    );

    // Check if we've successfuly bound local address
    if (!Network::Linux::SocketBindException::isError(bind_result)) {
      ::freeaddrinfo(serv_info); 
      return;
    }

    // Register socket bind error
    exception_builder.pushErrorString(
        Network::Linux::SocketBindException::getErrorString(errno)    
    );

    current_serv_info = current_serv_info->ai_next;
  }

  // We reached here b/c we failed to bind a local interface, so throw.
  throw exception_builder.build();
}
        
const Network::SystemConnectResults
Network::Linux::Connecter::connect(
    const Network::SystemConnectParameters & system_connect_parameters    
) {
  const Network::Ip::Host & remote_host_target =
      system_connect_parameters.getRemoteHost();

  struct addrinfo remote_hints, * remote_addr_info;
  ::memset(&remote_hints, 0, sizeof(remote_hints));

  Network::Linux::AddressFamilyTranslator address_family_translator;
  remote_hints.ai_family = address_family_translator
      .translateToOsCode(system_connect_parameters.getAddressFamily());
  
  Network::Linux::SocketTypeTranslator socket_type_translator;
  remote_hints.ai_socktype = socket_type_translator
      .translateToOsCode(system_connect_parameters.getSocketType());

  int get_remote_addr_info_result = ::getaddrinfo(
      remote_host_target.getAddress().getAddressString().c_str(),
      remote_host_target.getPort().toString().c_str(),
      &remote_hints,
      &remote_addr_info
  );

  if (Network::Linux::GetAddrInfoException::isError(get_remote_addr_info_result)) {
    throw Network::Linux::GetAddrInfoException(get_remote_addr_info_result);
  }

  int socket_descriptor;
  bool has_socket_descriptor = false;
  struct addrinfo * current_remote_addr_info = remote_addr_info;

  Network::Linux::SocketInitializationExceptionBuilder exception_builder;

  while (current_remote_addr_info) {
    // Attempt to open socket
    int socket_result = ::socket(
        current_remote_addr_info->ai_family,
        current_remote_addr_info->ai_socktype,
        current_remote_addr_info->ai_protocol
    );

    // Check for socket open error
    if (Network::Linux::SocketOpenException::isError(socket_result)) {
      exception_builder.pushErrorString(
          Network::Linux::SocketOpenException::getErrorString(errno)
      );

      // Try to initialize next iface
      current_remote_addr_info = current_remote_addr_info->ai_next;
      continue;
    }

    socket_descriptor = socket_result;

    // Bind before connect, if local host provided 
    if (system_connect_parameters.hasLocalHostConfig()) {
      bindLocalHostConfig(
          socket_descriptor,
          system_connect_parameters.getLocalHostConfig()
      ); 
    }

    // Connect to remote
    int connect_result = ::connect(
        socket_descriptor,
        current_remote_addr_info->ai_addr,
        current_remote_addr_info->ai_addrlen
    );  

    // Check for connect error
    if (Network::Linux::SocketConnectException::isError(connect_result)) {
      exception_builder.pushErrorString(
          Network::Linux::SocketConnectException::getErrorString(errno)
      );

      // Try to initialize next iface
      current_remote_addr_info = current_remote_addr_info->ai_next;
      continue;
    }

    has_socket_descriptor = true;
    ::freeaddrinfo(remote_addr_info);
    break;
  }

  return Network::SystemConnectResults(
      new Network::Linux::Connection(socket_descriptor)
  );
}

Network::Linux::Connecter::~Connecter() {}
