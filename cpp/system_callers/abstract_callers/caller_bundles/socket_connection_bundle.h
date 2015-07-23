#pragma once

#include "network_namespace.h"
#include "../writer/system_writer.h"
#include "../reader/system_reader.h"
#include "../closer/system_closer.h"

class Network::SocketConnectionBundle {

  private:
    const Network::SystemWriter * _systemWriter;
    const Network::SystemReader * _systemReader;
    const Network::SystemCloser * _systemCloser;

  public:
    SocketConnectionBundle(
        const Network::SystemWriter * _systemWriter,
        const Network::SystemReader * _systemReader,
        const Network::SystemCloser * _systemCloser
    );

    const Network::SystemWriter * getSystemWriter() const;
    const Network::SystemReader * getSystemReader() const;
    const Network::SystemCloser * getSystemCloser() const;

};
