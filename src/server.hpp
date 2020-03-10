#ifndef server_hpp_
#define server_hpp_

#include <string>
#include "serveroptions.hpp"

namespace setup_server
{
    class Server
    {
        public:
        Server(Server_Options);
        void Serve();
    };
}

#endif
