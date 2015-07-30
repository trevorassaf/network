#pragma once

#include <cstdlib>

namespace Network {
  template <typename Tdata> class Packet {

    private:
      const Tdata _data;
      const size_t _dataSize;

      Packet();
      void setData(const Tdata & data);

    public:
      Packet(const Tdata & data);
      const Tdata & getData() const;
      size_t getDataSize() const;
  };
};
