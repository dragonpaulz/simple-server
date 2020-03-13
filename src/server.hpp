#ifndef server_hpp_
#define server_hpp_

#include <boost/asio.hpp>
#include <string>

#include "serveroptions.hpp"

using boost::asio::ip::tcp;

namespace setup_server
{
    class Server
    {
        public:
        Server(boost::asio::io_context& io_context, Server_Options opts)
        : io_context_(io_context),
            acceptor_(io_context, tcp::endpoint(tcp::v4(), opts.port))
        {
            start_accept();
        }

        private:
            void start_accept();
            // void handle_accept(server_setup::Connection::pointer, const boost::system::error_code&);
            boost::asio::io_context& io_context_;
            tcp::acceptor acceptor_;
    };
}

#endif
