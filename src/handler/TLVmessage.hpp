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
        static bool ValueIsOfLen(TLVComponent::Length, TLVComponent::Value);

        TLVmessage(std::vector<char> in);
        
        bool getValid() {return _valid;}
        std::string to_string();

        TLVComponent::Type getMsgType() {return _type;}
        TLVComponent::Length getMsgLength() {return _len;}
        TLVComponent::Value getMsgValue() {return _value;}

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
        
        TLVComponent::Type _type;
        TLVComponent::Length _len;
        TLVComponent::Value _value;
        bool _valid;

        // Write out bytes to a specified stream
        void WriteBytes(std::string);
    };
}

#endif
