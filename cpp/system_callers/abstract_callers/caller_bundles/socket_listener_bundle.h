#pragma once

#include "network_namespace.h"
#include "../opener/system_opener.h"
#include "../binder/system_binder.h"
#include "../listener/system_listener.h"
#include "../closer/system_closer.h"

class Network::SocketListenerBundle {

  private:
    const Network::SystemOpener * _systemOpener;
    const Network::SystemBinder * _systemBinder;
    const Network::SystemListener * _systemListener;
    const Network::SystemCloser * _systemCloser;

  public:
    SocketListenerBundle(
        const Network::SystemOpener * _systemOpener,
        const Network::SystemBinder * _systemBinder,
        const Network::SystemListener * _systemListener,
        const Network::SystemCloser * _systemCloser
    );

    const Network::SystemOpener * getSystemOpener() const;
    const Network::SystemBinder * getSystemBinder() const;
    const Network::SystemListener * getSystemListener() const;
    const Network::SystemCloser * getSystemCloser() const;

};
