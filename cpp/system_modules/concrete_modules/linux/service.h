#pragma once

#include <system_modules/abstract_modules/service/system_service_module.h>

namespace Network {
  namespace Linux {
    class Service : public Network::SystemServiceModule {
      private:
        const unsigned int _socketDescriptor;

      public:
        Service(unsigned int socket_descriptor);
        const Network::SystemAcceptResults * accept() override;
        void close() override;
    };
  };
};
