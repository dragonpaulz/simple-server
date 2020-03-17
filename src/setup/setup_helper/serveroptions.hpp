#ifndef server_options_hpp_
#define server_options_hpp_

#include <cstdint>

namespace setup {
    class Server_Options {
        public:
        Server_Options(uint16_t);
        int port;
        const static uint16_t defaultPort = 1024;
    };
}

#endif