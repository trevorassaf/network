#pragma once

#include "time_namespace.h"

#include <cstdint>
#include <ctime>

class Network::TimeBuilder {

  private:
    static const uint32_t MICROS_PER_SEC;

    uint32_t _seconds;
    uint32_t _microSeconds;

  public:
    TimeBuilder();
    TimeBuilder & setSeconds(uint32_t secs);
    TimeBuilder & setMicroSecs(uint32_t micro_secs);
    TimeBuilder & from(const Network::Time & time);
    TimeBuilder & from(const timeval & os_time);
    const Network::Time build() const;
};
