#include <cstdint>
#include <string>
#include <iostream>

#include "serveroptions.hpp"

setup_server::Server_Options::Server_Options(int len, char** args)
{
    std::cout << "here"  << std::endl;
    // bool portDefined = false;
    if (len >= 3){
        std::cout << args[2] << std::endl;
        port = std::stoi(args[2]);
    } else {
        port = setup_server::Server_Options::defaultPort;
    }

    // if (!portDefined)
    // {
    //     std::cerr << "No port defined. Using default port at " <<
    //         setup_server::Server_Options::defaultPort<< std::endl;     
    //     port = setup_server::Server_Options::defaultPort;
    // }
}
