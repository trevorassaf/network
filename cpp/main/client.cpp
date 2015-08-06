#include <iostream>

#include <ip/host.h>
#include <ip/port_builder.h>
#include <ip/connecter_host_config.h>
#include <ip/address_family.h>
#include <ip/socket_type.h>

#include <system_modules/concrete_modules/linux/connecter.h>
#include <system_modules/abstract_modules/connecter/system_connect_parameters_builder.h>

#include <cassert>

int main (int argc, char **argv) {
  assert(argc == 3);
  const Network::Ip::Address address(argv[1]);     
  const Network::Ip::Port port = Network::Ip::PortBuilder()
      .setPortNumber(argv[2])
      .build();
  const Network::Ip::Host remote_host(
      Network::Ip::Address(argv[1]),
      Network::Ip::PortBuilder()
          .setPortNumber(argv[2])
          .build()
  );

  const Network::SystemConnectParameters connect_params = Network::SystemConnectParametersBuilder()
      .build(); 

  return 0;
}
