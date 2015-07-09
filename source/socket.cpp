#include "../headers/socket.h"

#include <stdexcept>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

const int Network::Tcp::Socket::TYPE = SOCK_STREAM;

const Network::Host * Network::Tcp::Socket::initHost(const addrinfo * addr) {
  const Network::Host * host = nullptr;

  switch (Network::Host::reverseAddressFamilyLookup(addr->ai_family)) {
    case Network::Host::AddressType::IPV4: {
      sockaddr_in * ipv4_addr = reinterpret_cast<sockaddr_in *>(addr->ai_addr);
      host = new Network::Host(
          Network::Ipv4(ipv4_addr->sin_addr.s_addr),
          Network::Port(ipv4_addr->sin_port)
      );
      break;
    }
    case Network::Host::AddressType::IPV6: {
      sockaddr_in6 * ipv6_addr = reinterpret_cast<sockaddr_in6 *>(addr->ai_addr);
      host = new Network::Host(
          Network::Ipv6(ipv6_addr->sin6_addr.s6_addr),
          Network::Port(ipv6_addr->sin6_port)
      );
      break;                                       
    }
    default:
      throw std::runtime_error(
          std::string("Invalid Network::Host::AddressType encountered: ") +
          std::to_string(addr->ai_family)
      );
      break;
  } 

  return host;
}

Network::Tcp::Socket::Socket(
  int socket_descriptor,
  const Network::Host * local
) :
  _socketDescriptor(socket_descriptor),
  _status(Network::Tcp::Socket::Status::CONNECTED),
  _isReuseAddr(false),
  _isReusePort(false),
  _isKeepAlive(false),
  _local(new Network::Host(*local)),
  _remote(nullptr)
{}

Network::Tcp::Socket::Socket() :
  _status(Network::Tcp::Socket::Status::CLOSED),
  _isReuseAddr(false),
  _isReusePort(false),
  _isKeepAlive(false),
  _local(nullptr),
  _remote(nullptr)
{}

Network::Tcp::Socket::~Socket() {
  delete _local;
  _local = nullptr;
  
  delete _remote;
  _remote = nullptr;
}

void Network::Tcp::Socket::open() {
  const Network::ClientConfig client_config;
  Network::Tcp::Socket::open(client_config);
}

void Network::Tcp::Socket::open(
    const Network::ClientConfig & client_config
) {
  if (_status != Network::Tcp::Socket::Status::CLOSED) {
    throw std::runtime_error("Must close socket first!");
  }

  struct addrinfo hints;
  ::memset(&hints, 0, sizeof(hints));
  hints.ai_family = client_config.getAddressFamily();
  hints.ai_socktype = Network::Tcp::Socket::TYPE;

  // Ip address config 
  const char * ip_address_str = nullptr;

  if (client_config.hasAddress()) {
    switch (client_config.getAddressType()) {
      case Network::ClientConfig::AddressType::IPV4:
        ip_address_str = client_config.getIpv4().toString().c_str();
        break;
      case Network::ClientConfig::AddressType::IPV6:
        ip_address_str = client_config.getIpv6().toString().c_str();
        break;
      default:
        throw std::runtime_error("Either ipv4 or ipv6 must be enabled if client has a valid address!");
    }
  }

  // Port config 
  const char * port_str = (client_config.hasPort()) ? client_config.getPort().toString().c_str() : nullptr;

  struct addrinfo *addrinfo_result_list = nullptr;
  int error_code = ::getaddrinfo(ip_address_str, port_str, &hints, &addrinfo_result_list);

  if (error_code) {
    throw Network::Exception::GetAddrInfoError(error_code);
  }

  const struct addrinfo * addrinfo_result = addrinfo_result_list;
  std::vector<int> error_codes;

  while (addrinfo_result) {
    int socket_output = ::socket(
        addrinfo_result->ai_family,
        addrinfo_result->ai_socktype,
        addrinfo_result->ai_protocol
    );

    // Accumulate error codes
    if (socket_output == -1) {
      error_codes.push_back(errno); 
    } else {
      _socketDescriptor = socket_output;
      break;
    }

    addrinfo_result = addrinfo_result->ai_next;
  }

  // Fail if we couldn't open socket on a network interface
  if (!addrinfo_result) {
    ::freeaddrinfo(addrinfo_result_list);
    throw Network::Exception::SocketError("Failed to open socket.", error_codes);
  }

  _status = Network::Tcp::Socket::Status::OPEN;

  // Bind to port, if set
  if (client_config.hasPort()) {
    int bind_output = ::bind(
        _socketDescriptor,
        addrinfo_result->ai_addr,
        addrinfo_result->ai_addrlen
    );

    if (bind_output == -1) {
      throw Network::Exception::NetworkRuntimeError(errno);
    }
  }
  
  initHost(addrinfo_result);
  ::freeaddrinfo(addrinfo_result_list);
}

Network::Tcp::Socket & Network::Tcp::Socket::connect(
    const Network::ServerConfig & server_config
) {
  if (_status == Network::Tcp::Socket::Status::OPEN) {
    throw std::runtime_error("Can't connect without opening connection first! Call socket.open()"); 
  }
 
  struct addrinfo hints, * addrinfo_result_list = nullptr;
  ::memset(&hints, 0, sizeof(hints));
  hints.ai_family = server_config.getIpAddressFamily();
  hints.ai_socktype = Network::Tcp::Socket::TYPE;

  int getaddrinfo_error_code = ::getaddrinfo(
    server_config.getAddressStr().c_str(),
    (server_config.hasPort())
        ? server_config.getPort().toString().c_str()
        : DEFAULT_PORT_STRING,
    &hints,
    &addrinfo_result_list
  );

  if (getaddrinfo_error_code) {
    throw Network::Exception::GetAddrInfoError(getaddrinfo_error_code);
  }

  const struct addrinfo * addrinfo_result = addrinfo_result_list;
  std::vector<int> error_codes;

  while (addrinfo_result) {
    int connect_output = ::connect(
        _socketDescriptor,
        addrinfo_result->ai_addr,
        addrinfo_result->ai_addrlen
    );

    if (connect_output != -1) {
      _status = Network::Tcp::Socket::Status::CONNECTED;
      break; 
    } 
    
    // Accumulate error codes and try to connect to next result
    error_codes.push_back(connect_output);
    addrinfo_result = addrinfo_result->ai_next;
  }

  // Check for initial connection failure
  if (!addrinfo_result) {
    ::freeaddrinfo(addrinfo_result_list);
    throw Network::Exception::SocketError("Failed to connect", error_codes);
  }

  initHost(addrinfo_result);
  ::freeaddrinfo(addrinfo_result_list);

  return *this;
}

Network::Tcp::Socket & Network::Tcp::Socket::listen() {
  const Network::ClientConfig client_config;
  listen(client_config); 
  return *this;
}

Network::Tcp::Socket & Network::Tcp::Socket::listen(const Network::ClientConfig & client_config) {
  if (_status != Network::Tcp::Socket::Status::CLOSED) {
    throw std::runtime_error("Socket already open! Must close socket before listening!");
  }

  // Open socket
  open(client_config);

  int listen_error_code = ::listen(_socketDescriptor, client_config.getBacklog());
  if (listen_error_code == -1) {
    throw Network::Exception::NetworkRuntimeError(
        errno,
        "Failed while attempting to listen on socket."
    );
  }
  return *this;
}

Network::Tcp::Socket Network::Tcp::Socket::accept() const {
  if (_status != Network::Tcp::Socket::Status::LISTENING) {
    throw std::runtime_error("Must be in listening state before we try to accept incomming connections");
  }
  
  sockaddr_storage remote_info;
  socklen_t remote_info_size = sizeof(remote_info);
  int accept_error_code = ::accept(
      _socketDescriptor,
      reinterpret_cast<sockaddr *>(&remote_info),
      &remote_info_size
  );

  if (accept_error_code == -1)  {
    throw Network::Exception::NetworkRuntimeError(
        errno,
        "Failed while attempting to accept incomming connection."
    );
  }

  Network::Tcp::Socket socket(accept_error_code, _local);
  Network::Host::AddressType address_type = 
      Network::Host::reverseAddressFamilyLookup(remote_info.ss_family);

  switch (address_type) {
    case Network::Host::AddressType::IPV4: 
      {
        const sockaddr_in & ipv4_local_info = 
            reinterpret_cast<sockaddr_in &>(remote_info);
        socket._remote = new Network::Host(
            Network::Ipv4(ipv4_local_info.sin_addr.s_addr),
            Network::Port(ipv4_local_info.sin_port)
        ); 
        break;
      }
    case Network::Host::AddressType::IPV6:  
      {
        const sockaddr_in6 & ipv6_local_info = 
            reinterpret_cast<sockaddr_in6 &>(remote_info);
        socket._remote = new Network::Host(
            Network::Ipv6(ipv6_local_info.sin6_addr.s6_addr),
            Network::Port(ipv6_local_info.sin6_port)
        ); 
        break;
      }
    default:
      throw std::runtime_error("Unknown ip type encountered while accepting connection!");
      break;
  }
  return socket;
}

Network::Tcp::Socket & Network::Tcp::Socket::close() {
  if (_status == Network::Tcp::Socket::Status::CLOSED) {
    throw std::runtime_error("Socket already closed! Can't close socket if it's not open!");
  }
  ::close(_socketDescriptor);
  _status = Network::Tcp::Socket::Status::CLOSED;
  return *this;
}

const Network::Host * Network::Tcp::Socket::getRemote() const {
  if (!_remote) {
    throw std::runtime_error("Server not set yet! Must invoke connect() in order to establish connection to server.");
  }
  return _remote;
}

const Network::Host * Network::Tcp::Socket::getLocal() const {
  if (!_local) {
    throw std::runtime_error("Client not set yet! Must call open() in order to establish client.");
  }
  return _local;
}
