#pragma once

#include "../network.h"
#include "../socket_config.h"

#include <string>

class Network::Ip::Config : public Network::SocketConfig {
  public:
    const std::string getBoundDevice() const;
    Network::Ip::Tcp::Config & bindDevice(const std::string & device_name);
};
