#include <iostream>
#include <boost/program_options.hpp>

#include "server.hpp"
#include "serveroptions.hpp"

namespace po = boost::program_options;

int main(int argc, char** argv)
{
    try
    {
        po::options_description desc("Allowed options");
            desc.add_options()
                ("port,p", po::value<std::uint16_t>()->required(), "define port to listen on")
            ;

        po::variables_map vm;
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);

        uint16_t port;
        if (vm.count("port"))
        {
            port = vm["port"].as<uint16_t>();
        }
        else
        {
            std::cerr << "port must be set." << std::endl;
            return 1;
        }

        setup_server::Server_Options options(port);
        setup_server::Server server(options);
        server.Serve();

        return 0;
    }
    catch(std::exception& e)
    {
        std::cerr << "error: " << e.what() << std::endl;
        return 1;
    }
    catch (...)
    {
        std::cerr << "unknown exception" << std::endl;
        return 1;
    }



}
