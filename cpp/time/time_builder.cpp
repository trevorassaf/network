#include "time.h"
#include "time_builder.h"

#include <cstdint>

const uint32_t Network::TimeBuilder::MICROS_PER_SEC = 1E6;

Network::TimeBuilder::TimeBuilder() :
    _seconds(0),
    _microSeconds(0)
{}

Network::TimeBuilder & Network::TimeBuilder::from(const Network::Time & time) {
  _seconds = time.getSeconds();
  _microSeconds = time.getMicroSeconds();
  return *this;
}

Network::TimeBuilder & Network::TimeBuilder::from(const timeval & os_time) {
  _seconds = os_time.tv_sec;
  _microSeconds = os_time.tv_usec;
  return *this;
}

Network::TimeBuilder & Network::TimeBuilder::setSeconds(uint32_t secs) {
  _seconds = secs;
  return *this;
}

Network::TimeBuilder & Network::TimeBuilder::setMicroSecs(uint32_t micros) {
  if (micros >= MICROS_PER_SEC) {
    _seconds += micros / Network::TimeBuilder::MICROS_PER_SEC;
    _microSeconds = (micros % Network::TimeBuilder::MICROS_PER_SEC);
  } else {
    _microSeconds = micros;
  }
  return *this;
}

const Network::Time Network::TimeBuilder::build() const {
  return Network::Time(_seconds, _microSeconds);
}
