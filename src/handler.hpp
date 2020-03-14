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
        enum types {hello, data, goodbye, unknown};

        types msgType;
        uint32_t msgLen;
        std::string msg;

        const static std::vector<uint8_t> helloBytes;
        const static std::vector<uint8_t> dataBytes;
        const static std::vector<uint8_t> goodbyeBytes;
        
        private:
        Data(bool);
        Data(types, int, std::string);

        static types GetTypeFromBytes(std::vector<uint8_t>);

        const static uint startType = 0;
        const static uint typeLen = 2;
        const static uint startLen = startType + typeLen;
        const static uint lenLen = 4;
        const static uint startData = startLen + lenLen;

        static Data InvalidInput() { return Data(false); };
        const static int minBytes = 6;
        
        bool valid;

        std::string ReadBytes();
        // Write out bytes to a specified stream
        void WriteBytes(std::string);
    };
}

#endif