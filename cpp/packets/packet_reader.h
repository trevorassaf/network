#pragma once

#include <packets/packet.h>

#include <system_modules/abstract_modules/connection/system_connection_module.h>
#include <system_modules/abstract_modules/connection/system_read_parameters.h>
#include <system_modules/abstract_modules/connection/system_read_results.h>
#include <system_modules/abstract_modules/connection/system_connection_module.h>

#include <stdexcept>
#include <cstring>

namespace Network {
  
  template <typename Tdata> class PacketReader {

    private:
      Network::SystemConnectionModule * _systemConnectionModule;

    public:
      PacketReader(
          Network::SystemConnectionModule * system_connection_module    
      );

      const Network::Packet<Tdata> read();
  };
};

template <typename Tdata>
Network::PacketReader<Tdata>::PacketReader(
    Network::SystemConnectionModule * system_connection_module    
) :
    _systemConnectionModule(system_connection_module)
{}

template <typename Tdata>
const Network::Packet<Tdata> Network::PacketReader<Tdata>::read() {
  size_t buffer_size = sizeof(Tdata);
  const Network::SystemReadParameters read_parameters(buffer_size);
  const Network::SystemReadResults read_results =
      _systemConnectionModule->read(read_parameters);
  
  Tdata raw_packet;
  ::memcpy(
      &raw_packet,
      read_results.getBuffer(),
      buffer_size
  );
  
  return Network::Packet<Tdata>(raw_packet);
}
