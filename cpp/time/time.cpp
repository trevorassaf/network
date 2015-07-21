#include "time.h"
#include "time_builder.h"

#include <cstdint>

Network::Time::Time(
    uint32_t seconds,
    uint32_t u_secs
) : 
    _seconds(seconds),
    _microSeconds(u_secs)
{}

uint32_t Network::Time::getSeconds() const {
  return _seconds;
}

uint32_t Network::Time::getMicroSeconds() const {
  return _microSeconds;
}

const timeval Network::Time::toTimeval() const {
  return timeval{_seconds, _microSeconds};
}
