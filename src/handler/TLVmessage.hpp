#ifndef handler_hpp_
#define handler_hpp_

#include <string>
#include <vector>

#include "Byte.hpp"
#include "TLVComponent/Type.hpp"
#include "TLVComponent/Value.hpp"
#include "TLVComponent/Length.hpp"

namespace handler
{
    class TLVmessage{
        public:
        TLVmessage(TLVComponent::Type, int, std::string);
        static TLVmessage Create(std::vector<char> in);
        static bool ValueIsOfLen(TLVComponent::Length, TLVComponent::Value);
        
        bool getValid() {return _valid;}

        TLVComponent::Type msgType;
        uint32_t msgLen;
        std::string msg;

        // TODO: This should read from each TLVComponent
        const static uint minChars = 12;
        const static uint minBytes = minChars/2;

        private:
        TLVmessage(bool v);

        // TODO: Get values from corresponding TLV component
        const static uint startType = 0;
        const static uint typeLenChar = 4;
        const static uint typeLenBytes = typeLenChar / 2;
        const static uint startLen = startType + typeLenBytes;

        static TLVmessage InvalidInput() { return TLVmessage(false); };
        
        bool _valid;

        // Write out bytes to a specified stream
        void WriteBytes(std::string);
    };
}

#endif
