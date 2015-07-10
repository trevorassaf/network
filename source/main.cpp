#include "../headers/socket.h"

#include <stdexcept>
#include <iostream>

int main() {
  Network::Tcp::Socket socket;
  socket.listen();
  const Network::Host & local = socket.getLocal();
  const Network::Port & port = local.getPort();
  std::cout << "Port: " << port.toString() << std::endl;
  switch (local.getAddressType()) {
    case Network::Host::AddressType::IPV4:
      {
        const Network::Ipv4 & ipv4 = local.getIpv4();
        std::cout << "Ipv4: " << ipv4.toString() << std::endl;
        break;
      }
    case Network::Host::AddressType::IPV6:
      {
        const Network::Ipv6 & ipv6 = local.getIpv6();
        std::cout << "Ipv6: " << ipv6.toString() << std::endl;
        break;
      }
    default:
      throw std::runtime_error("Invalid address type!");
      break;
  } 
  socket.close();
  return 0;
}
