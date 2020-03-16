#ifndef handler_hpp_
#define handler_hpp_

#include <string>
#include <vector>

#include "handler/Byte.hpp"
// #include "handler/MsgLen.hpp"

namespace handler
{
    class Data{
        public:
        enum types {hello, data, goodbye, unknown};
        Data(types, int, std::string);
        static Data Create(std::vector<char> in);
        
        bool getValid() {return _valid;}

        types msgType;
        uint32_t msgLen;
        std::string msg;

        const static std::vector<uint8_t> helloBytes;
        const static std::vector<uint8_t> dataBytes;
        const static std::vector<uint8_t> goodbyeBytes;

        const static uint minBytes = 6;

        private:
        Data(bool v);

        static types GetTypeFromBytes(std::vector<uint8_t>);

        const static uint startType = 0;
        const static uint typeLenChar = 4;
        const static uint typeLenBytes = typeLenChar / 2;
        const static uint startLen = startType + typeLenBytes;
        // const static uint startData = startLen + handler::MsgLen::nBytes;

        static Data InvalidInput() { return Data(false); };
        
        bool _valid;

        // Write out bytes to a specified stream
        void WriteBytes(std::string);
    };
}

#endif
