#include <cstdint>
#include <string>
#include <iostream>

#include "serveroptions.hpp"

setup::Server_Options::Server_Options(uint16_t port)
{
    this->port = port;
}
