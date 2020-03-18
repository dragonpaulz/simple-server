#ifndef connection_hpp_
#define connection_hpp_

#include "src/handler/TLVmessage.hpp"

#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>

#include <vector>

using boost::asio::ip::tcp;

namespace setup{
    class Connection : public boost::enable_shared_from_this<Connection>
    {
        public:
            Connection(boost::asio::io_context& io_context) : socket_(io_context){};
            typedef boost::shared_ptr<Connection> pointer;

            static pointer create(boost::asio::io_context& io_context)
            {
                return pointer(new Connection(io_context));
            }

            tcp::socket& socket() {
                return socket_;
            };
            void start();
        private:
            tcp::socket socket_;
            void handle_read(size_t);
            string to_string(TLVComponent::TLVmessage);
    };
}


#endif
