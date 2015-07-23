#pragma once

#include "network_namespace.h"
#include "../accepter/system_accepter.h"
#include "../closer/system_closer.h"

class Network::SocketServiceBundle {

  private:
    const Network::SystemAccepter * _systemAccepter;
    const Network::SystemCloser * _systemCloser;

  public:
    SocketServiceBundle(
        const Network::SystemAccepter * _systemAccepter,
        const Network::SystemCloser * _systemCloser
    );

    const Network::SystemAccepter * getSystemAccepter() const;
    const Network::SystemCloser * getSystemCloser() const;

};
