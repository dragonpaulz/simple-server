#include "src/handler/TLVmessage.hpp"
#include "connection.hpp"

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <iostream>
#include <string>
#include <vector>

using boost::asio::ip::tcp;

void setup::Connection::start()
{
    std::cout << "in connection start" << std::endl;
    std::string message_ = "E11000000000DA7A0000000501020304050B1E00000000";

    boost::asio::async_read(
        socket_,
        boost::asio::buffer(message_),
        boost::bind(
            &setup::Connection::handle_read,
            shared_from_this(),
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred
        )
    );
}

void setup::Connection::handle_read(const boost::system::error_code& error, size_t message)
{
    std::cout << "message: " << message << std::endl;
    std::vector<char> in(message);

    handler::TLVmessage msgIn(in);
    
    if (msgIn.getValid())
    {
        std::cout << "[ipaddress:port] [" << msgIn.getMsgType().to_string() << "] ["
            << msgIn.getMsgLength().getLen() << "] [" 
            << msgIn.getMsgValue().to_string() << "]" << std::endl;
    }
    else
    {
        std::cerr << "Invalid input: " << message << std::endl;
    }
    
}
