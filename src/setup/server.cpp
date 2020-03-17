#include <boost/asio.hpp>
#include <boost/bind.hpp>

#include "server.hpp"
#include "setup_helper/serveroptions.hpp"
#include "setup_helper/connection.hpp"

using boost::asio::ip::tcp;

void setup:: Server::start_accept()
{
setup::Connection::pointer new_connection =
    setup::Connection::create(io_context_);

setup::Server::acceptor_.async_accept(new_connection->socket(),
    boost::bind(&Server::handle_accept, this, new_connection,
        boost::asio::placeholders::error));
}

void setup::Server::handle_accept(setup::Connection::pointer new_connection,
    const boost::system::error_code& error)
{
    if (!error)
    {
        new_connection->start();
    }

    start_accept();
}
