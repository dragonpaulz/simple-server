#include "../../handler/TLVComponent/TLVmessage.hpp"
#include "connection.hpp"

#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <iostream>
#include <vector>

using boost::asio::ip::tcp;

void setup::Connection::start()
{
    std::cout << "in connection start" << std::endl;

    boost::asio::async_read(socket_, boost::asio::buffer(),
        boost::bind(&setup::Connection::handle_write, shared_from_this(),
          boost::asio::placeholders::error,
          boost::asio::placeholders::bytes_transferred));
}

void setup::Connection::handle_read(size_t message)
{
    // convert to message -> vector<char>
    std::vector<char> in();

    TLVComponent::TLVmessage msgIn(in);
    // additional checks with error logging for bad data here.
    // msg.isValid() to determine
    toString(msgIn);
}

std::string setup::Connection::to_string(TLVComponent::TLVmessage msg)
{
    // hard coding values. These are to be replaced
    // ip address could come from either client, or from somewhere in asio
    // port comes from server options
    std::cout << "[ipaddress:port] [" << msg.getMsgType().to_string() << "] ["
        << msg.getMsgLength().getLength() << "] [" 
        << msg.getValue().to_string() << "]" << std::endl;
}
