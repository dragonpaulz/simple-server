#ifndef server_hpp_
#define server_hpp_

#include <boost/asio.hpp>
#include <string>

#include "setup_helper/serveroptions.hpp"
#include "setup_helper/connection.hpp"

using boost::asio::ip::tcp;

namespace setup
{
    class Server : public boost::enable_shared_from_this<Server>
    {
        public:
        Server(boost::asio::io_context& io_context, Server_Options opts)
        : io_context_(io_context),
            acceptor_(io_context, tcp::endpoint(tcp::v4(), opts.getPort()))
        {
            start_accept();
        }

        private:
            void start_accept();
            void handle_accept(Connection::pointer, const boost::system::error_code&);
            boost::asio::io_context& io_context_;
            tcp::acceptor acceptor_;
    };
}

#endif
