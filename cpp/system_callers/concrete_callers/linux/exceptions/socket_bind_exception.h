#pragma once

class Network::Linux::SocketBindException {

  public:
    static bool isError(int error_code);
    static const std::string getErrorString(int error_code);
    SocketBindException(int error_code);
};
