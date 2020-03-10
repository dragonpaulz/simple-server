#include <iostream>
#include <server.hpp>
#include <serveroptions.hpp>

int main(int argc, char** argv)
{
    setup_server::Server_Options::Server_Options options(argv);
    setup_server::Server::Server server(options);
    server.Serve();
    delete &options;
    delete &server;
}
