#include "connection.hpp"
#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>

using boost::asio::ip::tcp;

class server_setup::Connection
  : public boost::enable_shared_from_this<server_setup::Connection>
{
public:
  typedef boost::shared_ptr<server_setup::Connection> pointer;

  static pointer create(boost::asio::io_context& io_context)
  {
    return pointer(new server_setup::Connection::Connection(io_context));
  }

  tcp::socket& socket()
  {
    return socket_;
  }

  void start()
  {
    // do something here
  }

private:

  void handle_write(const boost::system::error_code& /*error*/,
      size_t /*bytes_transferred*/)
  {
  }

  tcp::socket socket_;
  std::string message_;
};
