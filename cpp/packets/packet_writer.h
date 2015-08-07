#pragma once

#include <packets/packet.h>

#include <system_modules/abstract_modules/connection/system_connection_module.h>
#include <system_modules/abstract_modules/connection/system_write_parameters.h>

#include <stdexcept>
#include <cstdlib>
#include <cstdint>

namespace Network {
  template <typename Tdata> class PacketWriter {

    private:
      Network::SystemConnectionModule * _systemConnectionModule;

    public:
      PacketWriter(
          Network::SystemConnectionModule * system_connection_module    
      );

      void write(const Network::Packet<Tdata> & packet);
  };
};

template <typename Tdata>
Network::PacketWriter<Tdata>::PacketWriter(
    Network::SystemConnectionModule * system_connection_module    
) :
    _systemConnectionModule(system_connection_module)
{}

template <typename Tdata>
void Network::PacketWriter<Tdata>::write(
    const Network::Packet<Tdata> & packet
) {
  const Network::SystemWriteParameters write_params(
      reinterpret_cast<const uint8_t *>(&packet.getData()),
      sizeof(packet)    
  ); 
  _systemConnectionModule->write(write_params);
}
