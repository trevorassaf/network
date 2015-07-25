#include "connection.h"

#include "../system_callers/abstract_callers/caller_modules/system_connection_module.h"

void Network::TcpIpv4Socket::Connection::close() {
   _systemConnectionModule
      ->getSystemCloser()
      ->close(); 
}

Network::TcpIpv4Socket::Connection(
    Network::SystemConnectionModule * system_connection_module,
    const Network::Ip::V4::Host * local_host,
    const Network::Ip::V4::Host * remote_host
) :
    _systemConnectionModule(system_connection_module),
    _localHost(local_host),
    _remoteHost(remote_host)
{}

Network::TcpIpv4Socket::~Connection() {
  delete _systemConnectionModule;
  delete _localHost;
  delete _remoteHost;
}

const Network::Ip::V4::Host * Network::TcpIpv4Socket::getLocalHost() const {
  return _localHost;
}

const Network::Ip::V4::Host * Network::TcpIpv4Socket::getRemoteHost() const {
  return _remoteHost;
}

template <typename Tdata>
void Network::TcpIpv4Socket::write<Tdata>(const Network::Packet<Tdata> * data) const {
  const Network::SystemWriteParameters<Tdata> write_params(data);
  _systemConnectionModule
      ->getSystemWriter()
      ->write(write_params);
}

template <typename Tdata>
const Network::Packet<Tdata> * Network::TcpIpv4Socket::read<Tdata>() const {
  const Network::SystemReadResults * read_results =
      _systemConnectionModule
          ->getSystemReader()
          ->read();
  return read_results->getPacket();
}
