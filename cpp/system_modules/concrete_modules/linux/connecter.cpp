#include "connecter.h"

#include <system_modules/concrete_modules/linux/exceptions/getaddrinfo_exception.h>
#include <system_modules/concrete_modules/linux/exceptions/socket_initialization_exception_builder.h>
#include <system_modules/concrete_modules/linux/exceptions/socket_open_exception.h>
#include <system_modules/concrete_modules/linux/exceptions/socket_bind_exception.h>
#include <system_modules/concrete_modules/linux/exceptions/socket_listen_exception.h>

#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <ifaddrs.h>
        
const Network::SystemConnectResults *
Network::SystemConnecterModule::connect(
    const Network::SystemConnectParameters & system_connect_parameters    
) {
  const Network::Ip::Host & remote_host =
      system_connect_parameters.getRemoteHost();
  const Network::Ip::Address & address = remote_host.getAddress();
  const Network::Ip::Port & port = remote_host.getPort();

  const Network::Ip::AddressFamily address_family =
      system_connect_parameters.getAddressFamily();
  const Network::Ip::SocketType socket_type =
      system_connect_parameters.getSocketType();

  struct addrinfo remote_hints, *remote_addr_info;
  ::memset(&remote_hints, 0, sizeof(remote_hints));

  Network::Linux::AddressFamilyTranslator adress_family_translator;
  remote_hints.ai_family = address_family_translator.translateToOsCode(address_family);
  
  Network::SocketTypeTranslator socket_family_translator;
  remote_hints.ai_socktype = socket_type_translator.translateToOsCode(socket_type);

  int get_remote_addr_info_result ::getaddrinfo(
      remote_host.getAddress().toAddressString().c_str(),
      remote_host.getPort().toString().c_str(),
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
    
  }

}
