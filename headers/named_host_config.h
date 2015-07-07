#pragma once

#include <unordered_map>
#include <functional>
#include <string>

#include "network.h"
#include "host_config.h"
#include "ipv4.h"
#include "ipv6.h"
#include "port.h"

class Network::NamedHostConfig : public Network::HostConfig {
    private:
      /**
       * Indicates if domain is set.
       */
      bool _hasDomain;

      /**
       * Host domain name.
       */
      std::string _domain;

    public:
      /**
       * NamedHostConfig()
       * - Defaults to localhost with unspecified ip with unspecified port.
       */
      NamedHostConfig();




};
