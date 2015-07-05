#include "../headers/socket.h"

#include <stderror>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

const int Network::Tcp::Socket::TYPE = SOCK_STREAM;

Network::Tcp::Socket::Socket() :
    _protocol(Network::Tcp::Socket::DEFAULT_PROTOCOL),
    _status(Network::Tcp::Socket::Status::CLOSED)
{}

Socket & open() {
  struct addrinfo hints;
  ::memset(&hints, 0, sizeof(hints));
  hints.ai_family = _client.getAddressFamily();
  hints.ai_socktype = Network::Tcp::Socket::TYPE;

  // Ip address config 
  const char * ip_address_str = nullptr;

  if (_client.hasAddress()) {
    switch (_client.getAddressType()) {
      case Network::Host::AddressType::IPV4:
        ip_address_str = _client.getIpv4().toString().c_str();
        break;
      case Network::Host::AddressType::IPV6:
        ip_address_str = _client.getIpv6().toString().c_str();
        break;
      default:
        throw std::runtime_error("Either ipv4 or ipv6 must be enabled if client has a valid address!");
    }
  } else {
    hints.ai_hints = AI_PASSIVE;  // bind any ip address!
  }

  // Port config 
  const char * port_str = (_client.hasPort()) ? _client.getPort().toString().c_str() : nullptr;

  struct addrinfo *addrinfo_results;
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

  // Bind to port, if set
  if (_hasPort) {
    int bind_output = ::bind(_socketDescriptor, result->ai_addr, result->ai_addrlen);
    if (bind_output == -1) {
      throw Network::Exception::NetworkRuntimeError(errno);
    }
  }

  // Extract client information
  // Ip address
  if (result->sa_family == AF_INET) {           // ipv4
    if (!_client.hasAddress()) {
      uint32_t ipv4_address = static_cast<const sockaddr_in *>(result)->sin_addr.s_addr;
      _client.setIpv4(Network::Ipv4(ipv4_address));
    }
  } else if (result->sa_family == AF_INET6) {   // ipv6
    if (!_client.hasAddress()) {
      _client.setIpv6(Network::Ipv6(static_cast<const sockaddr_in6 *>(result)->sin6_addr.s6_addr)); 
    }
  } else {
    throw std::runtime_error(std::string("Unknown sa_family: ") + std::to_string(result->sa_family));
  }

  // Port
  if (_client.hasPort()) {
    _client.setPort(Network::Port(static_cast<const sockaddr_in6 *>(result)->sin6_port)); 
  }
    
}
