#include "service_builder_factory.h"

#include "../system_callers/concrete_callers/linux/service_builder_module.h"

Network::ServiceBuilder * Network::TcpIpv4Socket::ServiceBuilder::Factory::getNewInstance() {
    Network::LinuxServiceBuilderModule * linux_service_builder_module =
        new Network::LinuxServiceBuilderModule();
    return new Network::ServiceBuilder(linux_service_builder_module);
}
