#include <iostream>
#include <system_modules/concrete_modules/linux/service_builder.h>
#include <system_modules/concrete_modules/linux/service.h>
#include <system_modules/abstract_modules/service_builder/system_listen_parameters.h>
#include <system_modules/abstract_modules/service_builder/system_listen_results.h>
#include <ip/service_host_config_builder.h>
#include <ip/host.h>
#include <ip/address.h>
#include <ip/port.h>
#include <ip/port_config.h>

int main() {
  const Network::Ip::Port port(3000);
  const Network::Ip::PortConfig port_config(port);

  const Network::Ip::ServiceHostConfig service_host_config =
      Network::Ip::ServiceHostConfigBuilder()
          .setSocketType(Network::Ip::SocketType::STREAM)
          .setPortConfig(port_config)
          .build();

  const Network::SystemListenParameters listen_parameters(service_host_config);
  Network::SystemServiceBuilderModule * service_builder_module =
      new Network::Linux::ServiceBuilder();
  Network::SystemListenResults * listen_results =
      service_builder_module->listen(
          &listen_parameters
      );

  Network::SystemServiceModule * service_module = listen_results
      ->moveSystemServiceModule();

  const Network::SystemServiceModule::ListeningHosts & listening_hosts =
      service_module->getListeningHosts();

  for (const auto & host : listening_hosts) {
    std::cout << host.getAddress().getAddressString() << ":"
        << host.getPort().toString() << std::endl;
  }

  Network::SystemAcceptResults accept_results = service_module->accept();

  Network::SystemConnectionModule * connection_module =
      accept_results.moveSystemConnectionModule();

  const Network::Ip::Host & remote_host = connection_module->getRemoteHost();
  const Network::Ip::Host & local_host = connection_module->getLocalHost();

  std::cout << "Remote host: " << remote_host.getAddress().getAddressString()
      << remote_host.getPort().toString() << std::endl;
  std::cout << "Local host: " << local_host.getAddress().getAddressString()
      << local_host.getPort().toString() << std::endl;

  //delete connection_module;
  //delete service_module;

  return 0;
}
