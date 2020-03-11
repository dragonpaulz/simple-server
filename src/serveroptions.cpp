#include <cstdint>

#include "serveroptions.hpp"

setup_server::Server_Options::Server_Options(char** args)
{
    port = setup_server::Server_Options::defaultPort;
    return;
}
