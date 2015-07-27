#include "service.h"

Network::Service::Service(
    Network::SystemServiceModule * system_service_module
) :
    _systemServiceModule(system_service_module),
    _ipv4HostConfig(nullptr)
    _isListening(false)
{}

Network::Service * Network::Service::setHostConfig(
    const Network::Ip::V4::LocalHostConfig * local_host_config    
) {}
