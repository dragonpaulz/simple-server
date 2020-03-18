#include "src/handler/TLVmessage.hpp"
#include "connection.hpp"

#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <iostream>
#include <string>
#include <vector>

using boost::asio::ip::tcp;

void setup::Connection::start()
{
    std::cout << "in connection start" << std::endl;

    boost::asio::async_read(socket_, boost::asio::buffer(),
        boost::bind(&setup::Connection::handle_read, shared_from_this(),
          boost::asio::placeholders::error,
          boost::asio::placeholders::bytes_transferred));
}

void setup::Connection::handle_read(size_t message)
{
    std::vector<char> in(message);

    handler::TLVmessage msgIn(in);
    // additional checks with error logging for bad data here.
    // msg.isValid() to determine
    std::cout << "[ipaddress:port] [" << msgIn.getMsgType().to_string() << "] ["
        << msgIn.getMsgLength().getLen() << "] [" 
        << msgIn.getMsgValue().to_string() << "]" << std::endl;
}
