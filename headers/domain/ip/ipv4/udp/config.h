#pragma once

#include "../../network.h"
#include "../config.h"

class Network::Ip::Udp::Config : public Network::Ip::Config {

  public:
    bool isBroadcast() const;
    void setIsBroadcast(bool is_broadcast);
    void enableBroadcast();
    void disableBroadcast();


};
