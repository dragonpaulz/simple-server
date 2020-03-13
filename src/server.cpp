#include <boost/asio.hpp>
#include <boost/bind.hpp>

#include "server.hpp"
#include "serveroptions.hpp"
#include "connection.hpp"

using boost::asio::ip::tcp;

class setup_server::Server  : public boost::enable_shared_from_this<Server>{
    public:
    Server(boost::asio::io_context& io_context, Server_Options opts)
    : io_context_(io_context),
        acceptor_(io_context, tcp::endpoint(tcp::v4(), opts.port))
    {
        start_accept();
    }

    void Serve()
    {

        // starts server
        return;
    }

    private:
    boost::asio::io_context& io_context_;
    tcp::acceptor acceptor_;

    void start_accept()
    {
    server_setup::Connection::pointer new_connection =
        server_setup::Connection::create(io_context_);

    acceptor_.async_accept(new_connection->socket(),
        boost::bind(&Server::handle_accept, this, new_connection,
            boost::asio::placeholders::error));
    }

    void handle_accept(server_setup::Connection::pointer new_connection,
        const boost::system::error_code& error)
    {
        if (!error)
        {
            new_connection->start();
        }

        start_accept();
    }
};
