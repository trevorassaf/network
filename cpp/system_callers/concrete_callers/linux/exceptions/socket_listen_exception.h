#pragma once

class Network::Linux::SocketListenException {

  public:
    static bool isError(int error_code);
    static const std::string getErrorString(int error_code);
    SocketListenException(int error_code);
};
