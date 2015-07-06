#include "../headers/socket.h"

#include <stderror>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

const int Network::Tcp::Socket::TYPE = SOCK_STREAM;

Network::Tcp::Socket::Socket() :
  _status(Network::Tcp::Socket::CLOSED),
  _isReuseAddr(false),
  _isReusePort(false),
  _isKeepAlive(false)
{}

Network::Tcp::Socket & Network::Tcp::Socket::open() {
  const Network::ClientConfig client_config;
  return Network::Tcp::Socket(client_config);
}

Network::Tcp::Socket & Network::Tcp::Socket::open(const Network::ClientConfig & client_config) {
  if (_status != Network::Tcp::Socket::Status::CLOSED) {
    throw std::runtime_error("Must close socket first!");
  }

  struct addrinfo hints;
  ::memset(&hints, 0, sizeof(hints));
  hints.ai_family = _clientConfig.getAddressFamily();
  hints.ai_socktype = Network::Tcp::Socket::TYPE;

  // Ip address config 
  const char * ip_address_str = nullptr;

  if (_clientConfig.hasAddress()) {
    switch (_clientConfig.getAddressType()) {
      case Network::ClientConfig::AddressType::IPV4:
        ip_address_str = _clientConfig.getIpv4().toString().c_str();
        break;
      case Network::ClientConfig::AddressType::IPV6:
        ip_address_str = _clientConfig.getIpv6().toString().c_str();
        break;
      default:
        throw std::runtime_error("Either ipv4 or ipv6 must be enabled if client has a valid address!");
    }
  }

  // Port config 
  const char * port_str = (_clientConfig.hasPort()) ? _clientConfig.getPort().toString().c_str() : nullptr;

  struct addrinfo *addrinfo_results = nullptr;
  int error_code = ::getaddrinfo(ip_address_str, port_str, &hints, &addrinfo_results);

  if (error_code) {
    throw Network::Exception::GetAddrInfoError(error_code);
  }

  const struct addrinfo result = addrinfo_results;
  std::vector<int> error_codes;

  while (result) {
    int socket_ouput = ::socket(result->ai_family, res->ai_socktype, res->ai_protocol);

    if (socket_ouput == -1) {
      error_codes.push_back(errno); 
    } else {
      _socketDescriptor = socket_output;
      break;
    }

    result = result->ai_next;
  }

  if (!result) {
    ::freeaddrinfo(addrinfo_results);
    throw Network::Exception::SocketError(error_codes);
  }

  _status = Network::Tcp::Socket:OPEN;

  // Bind to port, if set
  if (_clientConfig.hasPort()) {
    int bind_output = ::bind(_socketDescriptor, result->ai_addr, result->ai_addrlen);
    if (bind_output == -1) {
      throw Network::Exception::NetworkRuntimeError(errno);
    }
  }

  // Extract client information
  // Ip address
  switch (result->sa_family) {
    case AF_INET:
      const struct sockaddr_in * ipv_addr = static_cast<const sockaddr_in_*>(result->ai_addr);
      _client = new Network::Host(
          Network::Ipv4(ipv4_addr->sin_addr.s_addr),
          Network::Port(ipv4_addr->sin_port)
      );
      break;
    case AF_INET6:
      _client = new Network::Host(
          Network::Ipv6(ipv6_addr->sin6_addr.s6_addr),
          Network::Port(ipv6_addr->sin6_port)
      );
      break;
    default:
      throw std::runtime_error(std::string("Unknown sa_family: ") + std::to_string(result->sa_family));
      break;
  }
}

Network::Tcp::Socket & Network::Tcp::Socket::connect(const Network::ServerConfig & server_config) {
  if (_status == Network::Tcp::Socket::Status::OPEN) {
    throw std::runtime_error("Can't connect without opening connection first! Call socket.open()"); 
  }
 
  struct addrinfo hints, * results;
  ::memset(&hints, 0, sizeof(hints));
  hints.ai_family = server_config.getAddressFamily();
  hints.ai_socktype = Network::Tcp::Socket::TYPE;
   
}
