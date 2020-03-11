#ifndef server_options_hpp_
#define server_options_hpp_

#include <cstdint>

namespace setup_server {
    class Server_Options {
        public:
        Server_Options(int, char**);
        int port;
        const static uint16_t defaultPort = 1024;
    };
}

#endif