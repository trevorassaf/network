#include <iostream>

#include <ip/host.h>
#include <ip/port_builder.h>
#include <ip/connecter_host_config.h>
#include <ip/address_family.h>
#include <ip/socket_type.h>

#include <system_modules/concrete_modules/linux/connecter.h>
#include <system_modules/abstract_modules/connecter/system_connect_parameters_builder.h>
#include <system_modules/abstract_modules/connecter/system_connect_parameters.h>
#include <system_modules/abstract_modules/connecter/system_connect_results.h>

#include <cassert>

int main (int argc, char **argv) {
  assert(argc == 3);
  const Network::Ip::Host remote_host_target(
      Network::Ip::Address(argv[1]),
      Network::Ip::PortBuilder()
          .setPortNumber(argv[2])
          .build()
  );

  const Network::SystemConnectParameters connect_params =
      Network::SystemConnectParametersBuilder()
          .setRemoteHost(remote_host_target)
          .build(); 

  Network::SystemConnecterModule * system_connecter_module = new Network::Linux::Connecter();
  Network::SystemConnectResults connect_result =
      system_connecter_module->connect(connect_params); 

  Network::SystemConnectionModule * connection_module =
      connect_result.moveSystemConnectionModule();
  
  const Network::Ip::Host & remote_host = connection_module->getRemoteHost();
  const Network::Ip::Host & local_host = connection_module->getLocalHost();

  std::cout << "Remote host: " << remote_host.getAddress().getAddressString()
      << remote_host.getPort().toString() << std::endl;
  std::cout << "Local host: " << local_host.getAddress().getAddressString()
      << local_host.getPort().toString() << std::endl;

  //delete connection_module;
  //delete system_connecter_module;

  return 0;
}
