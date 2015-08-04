#include "connecter.h"
        
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

  return nullptr;
}
