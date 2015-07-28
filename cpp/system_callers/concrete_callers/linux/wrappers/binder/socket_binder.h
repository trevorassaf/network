#pragma once

#include "linux_namespace.h"
#include "../../../abstract_callers/binder/socket_binder.h"

class Network::Linux::SocketBinder :
    public Network::SocketBinder {

  private:
    int _socketDescriptor;
    struct sockaddr_storage _socketAddressStorage;
    socklen_t _socketAddressStorageLength;

  protected:
    const Network::SystemBindParameters *
        assembleSystemBindParameters() const override;
    
    void cacheSystemBindResults(
        const Network::SystemBindResults * system_bind_results    
    ) const override;

    virtual int getSocketType() const = 0;
    virtual int getSocketDomain() const = 0;
    virtual int getSocketProtocol() const = 0;
};
