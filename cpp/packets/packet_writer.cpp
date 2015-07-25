#include "packet_writer.h"

template <typename Tdata>
Network::PacketWriter<Tdata>::PacketWriter(const Network::Packet<Tdata> & packet) : 
    _packet(packet),
    _bytesRemaining(sizeof(Tdata))
{}
