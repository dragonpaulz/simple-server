#include "connection.hpp"
#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <iostream>

using boost::asio::ip::tcp;

// static setup::Connection::pointer setup::Connection::create(boost::asio::io_context& io_context)
// {
    
// }

void setup::Connection::start()
{
    std::cout << "in connection start" << std::endl;
    // do something here
}

void setup::Connection::handle_write(const boost::system::error_code& /*error*/,
    size_t /*bytes_transferred*/)
{
}
