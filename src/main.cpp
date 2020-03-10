#include <iostream>
#include "server.hpp"
#include "serveroptions.hpp"

int main(int argc, char** argv)
{
    setup_server::Server_Options options(argv);
    setup_server::Server server(options);
    delete &options;
    server.Serve();
    delete &server;
}
