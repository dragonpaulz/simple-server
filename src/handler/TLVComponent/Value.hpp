#ifndef TLV_VALUE_HPP
#define TLV_VALUE_HPP

#include <vector>

namespace TLVComponent
{
    class Value
    {
        public:
            Value(std::vector<char> v) {value = v;}
            std::vector<char> value;
    };
}

#endif
