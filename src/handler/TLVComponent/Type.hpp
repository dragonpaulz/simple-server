#ifndef TLVCOMPONENT_TYPE_HPP
#define TLVCOMPONENT_TYPE_HPP

#include <vector>

namespace TLVComponent
{
    class Type
    {
        public:
        Type() { _type = unknown; }
        Type(std::vector<char>);
        
        enum types {hello, data, bye, unknown};

        bool isValid() {return _valid; }
        types getType() {return _type; }

        const static std::vector<char> helloChars;
        const static std::vector<char> dataChars;
        const static std::vector<char> byeChars;
        
        private:
        bool _valid;
        types _type;
    };
}

#endif
