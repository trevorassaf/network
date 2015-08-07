#pragma once

namespace Network {

  template <typename Tdata> class Packet {

    private:
      const Tdata _data;

    public:
      Packet(const Tdata & data);
      const Tdata & getData() const;
  };
};

template <typename Tdata>
Network::Packet<Tdata>::Packet(const Tdata & data) :
    _data(data)
{}

template <typename Tdata>
const Tdata & Network::Packet<Tdata>::getData() const {
  return _data;
}
