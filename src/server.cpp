#include <boost/asio.hpp>

#include "server.hpp"
#include "serveroptions.hpp"

using boost::asio::ip::tcp;

class setup_server::Server{

    Server(Server_Options options)
    {
        int port = options.port;
    };

    void Serve()
    {

        // starts server
        return;
    }
};
