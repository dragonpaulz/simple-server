#ifndef connection_hpp_
#define connection_hpp_

#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>

using boost::asio::ip::tcp;

namespace server_setup{
    class Connection : public boost::enable_shared_from_this<Connection>
    {
        public:
            Connection(boost::asio::io_context& io_context) : socket_(io_context){};
            typedef boost::shared_ptr<Connection> pointer;
            static pointer create(boost::asio::io_context& io_context);
            tcp::socket& socket();
            void start();
        private:
            void handle_write(const boost::system::error_code&, size_t);
            tcp::socket socket_;
            std::string message_;
    };
}


#endif
