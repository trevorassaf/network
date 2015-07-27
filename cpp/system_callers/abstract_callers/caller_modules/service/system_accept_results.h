#pragma once

#include "network_namespace.h"
#include "../connection/system_connection_module.h"
#include "../../../../ip/port.h"

#include <string>

class Network::SystemAcceptResults {

  private:
    const Network::SystemConnectionModule * _systemConnectionModule;
    const std::string _ipString;
    const Network::Ip::Port _port;

  public:
    SystemAcceptResults(
        const Network::SystemConnectionModule * _systemConnectionModule
    );

    const Network::SystemConnectionModule * getSystemConnectionModule() const;
    const std::string & getIpString() const;
    const Network::Ip::Port getPort() const;
};
