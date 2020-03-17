#ifndef handler_hpp_
#define handler_hpp_

#include <string>
#include <vector>

#include "handler/Byte.hpp"
#include "handler/TLVComponent/Type.hpp"
// #include "handler/MsgLen.hpp"

namespace handler
{
    class Data{
        public:
        // TODO: Remove next line and fix references to be in TLVComponent
        enum types {hello, data, goodbye, unknown};
        Data(TLVComponent::Type, int, std::string);
        static Data Create(std::vector<char> in);
        
        bool getValid() {return _valid;}

        // TODO: Update types to TLVComponent ns
        TLVComponent::Type msgType;
        uint32_t msgLen;
        std::string msg;

        // TODO: Remove next couple of lines.
        const static std::vector<uint8_t> helloBytes;
        const static std::vector<uint8_t> dataBytes;
        const static std::vector<uint8_t> goodbyeBytes;

        const static std::vector<char> helloChars;
        const static std::vector<char> dataChars;
        const static std::vector<char> goodbyeChars;

        // TODO: This should read from each TLVComponent
        const static uint minChars = 12;
        const static uint minBytes = minChars/2;

        private:
        Data(bool v);

        // TODO: Remove
        static types GetTypeFromBytes(std::vector<uint8_t>);

        // TODO: Get values from corresponding TLV component
        const static uint startType = 0;
        const static uint typeLenChar = 4;
        const static uint typeLenBytes = typeLenChar / 2;
        const static uint startLen = startType + typeLenBytes;

        static Data InvalidInput() { return Data(false); };
        
        bool _valid;

        // Write out bytes to a specified stream
        void WriteBytes(std::string);
    };
}

#endif
