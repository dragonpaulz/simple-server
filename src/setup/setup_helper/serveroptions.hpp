#ifndef server_options_hpp_
#define server_options_hpp_

#include <cstdint>

namespace setup {
    class Server_Options
    {
        public:
        Server_Options(uint16_t);
        int getPort() { return _port;}

        private:
        int _port;
    };
}

#endif