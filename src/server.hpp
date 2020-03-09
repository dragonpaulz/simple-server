#ifndef server_hpp_
#define server_hpp_

#include <string>

namespace setup_server
{
    class Server
    {
    public:
        Server Parse_server_options(std::string);
        void Run_server();
    };
}

#endif