#ifndef handler_hpp_
#define handler_hpp_

#include <string>
#include <vector>

namespace handler
{
    class Data{
        public:
        static Data Create(std::vector<uint8_t> in);
        // TODO: figure out a better way to represent the information, maybe with stoi?
        enum Types {hello, data, goodbye};

        Types msgType;
        uint32_t msgLen;
        std::string msg;

        const static std::vector<uint8_t> helloBytes;
        const static std::vector<uint8_t> dataBytes;
        const static std::vector<uint8_t> goodbyeBytes;
        
        private:
        Data(bool);
        Data(std::vector<uint8_t>, std::vector<uint8_t>, std::vector<uint8_t>);

        static Data InvalidInput() { return Data(false); };
        const static int minBytes = 6;
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