#pragma once

namespace Network {
  class SystemConnectResults {
    private:
      Network::SystemConnectionModule * _systemConnectionModule;

    public:
      SystemConnectResults(
          Network::SystemConnectionModule * system_connection_module    
      );
      ~SystemConnectResults();
      Network::SystemConnectionModule * moveSystemConnectionModule();
  };
};
