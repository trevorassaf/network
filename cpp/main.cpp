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
  const Network::Ip::ServiceHostConfig service_host_config =
      Network::Ip::ServiceHostConfigBuilder()
          .setSocketType(Network::Ip::SocketType::STREAM)
//          .setPortConfig(Network::Ip::PortConfig(3000))
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

  const Network::SystemAcceptResults * accept_results = service_module->accept();
  std::cout << "Accepted!" << std::endl;

  delete service_module;
  return 0;
}
