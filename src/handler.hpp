#ifndef handler_hpp_
#define handler_hpp_

#include <string>
#include <vector>

namespace handler
{
    class Data{
        public:
        Data Create(std::vector<uint8_t> in);
        // TODO: figure out a better way to represent the information, maybe with stoi?
        const static std::vector<uint8_t> hello;
        const static std::vector<uint8_t> data;
        const static std::vector<uint8_t> goodbye;
        
        private:
        uint8_t type[]; // 2 bytes
        uint8_t length[]; // 4 bytes
        uint8_t message[]; // variable number of bytes, based on length value
        
        bool valid;

        std::string ReadBytes();
        // Write out bytes to a specified stream
        void WriteBytes(std::string);
    };
}

#endif