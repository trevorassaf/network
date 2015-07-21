#pragma once

#include "time_namespace.h"

#include <cstdint>
#include <ctime>

class Network::Time {

  private:
    const uint32_t _seconds;
    const uint32_t _microSeconds;
   
    friend class Network::TimeBuilder;

    Time(uint32_t secs=0, uint32_t u_secs=0);

  public:
    uint32_t getSeconds() const;
    uint32_t getMicroSeconds() const;
    const timeval toTimeval() const;
};
