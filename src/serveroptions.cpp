#include <cstdint>
#include <string>
#include <iostream>

#include "serveroptions.hpp"

setup_server::Server_Options::Server_Options(uint16_t port)
{
    this->port = port;
}
