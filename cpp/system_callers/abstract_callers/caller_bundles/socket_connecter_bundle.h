#pragma once

#include "network_namespace.h"
#include "../opener/system_opener.h"
#include "../binder/system_binder.h"
#include "../connecter/system_connecter.h"
#include "../closer/system_closer.h"

class Network::SocketConnecterBundle {

  private:
    const Network::SystemOpener * _systemOpener;
    const Network::SystemBinder * _systemBinder;
    const Network::SystemConnecter * _systemConnecter;
    const Network::SystemCloser * _systemCloser;

  public:
    SocketConnecterBundle(
        const Network::SystemOpener * _systemOpener,
        const Network::SystemBinder * _systemBinder,
        const Network::SystemConnecter * _systemConnecter,
        const Network::SystemCloser * _systemCloser
    );

    const Network::SystemOpener * getSystemOpener() const;
    const Network::SystemBinder * getSystemBinder() const;
    const Network::SystemConnecter * getSystemConnecter() const;
    const Network::SystemCloser * getSystemCloser() const;

};
