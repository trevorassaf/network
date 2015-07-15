#pragma once

#include "network.h"

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
    const Network::Time build() const;
};

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
