#include "../../../headers/ip/tcp/service_builder.h"

int Network::Ip::Tcp::openTcpIpServiceSocket() const {

}

Network::ServiceBuilder::ServiceBuilder() : 
    _isHostSet(false),
    _backlogSize(DEFAULT_BACKLOG_SIZE)
{}

Network::SocketConfig::Type 
Network::Tcp::Ip::getType() const {
  return Network::SocketConfig::Type::TCP; 
}

Network::SocketConfig::AddressFamily
Network::Ip::Tcp::getAddressFamily() const {
   
}

Network::Tcp::Ip::Service *
Network::Ip::Tcp::build() const {
  
}

Network::Ip::Tcp::ServiceBuilder &
Network::Ip::Tcp::ServiceBuilder::setHost(const Network::Host & host) {
  _isHostSet = true; 
  _hostBuilder.from(host);
}
