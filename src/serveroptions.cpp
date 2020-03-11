#include <cstdint>
#include <string>
#include <iostream>

#include "serveroptions.hpp"

setup_server::Server_Options::Server_Options(int len, char** args)
{
    bool portDefined = false;
    // std::cout << args[2] << std::endl;

    port = std::stoi(args[2]);

    if (!portDefined)
    {
        std::cerr << "No port defined. Using default port at " <<
            setup_server::Server_Options::defaultPort<< std::endl;     
        port = setup_server::Server_Options::defaultPort;
    }
}
