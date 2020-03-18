#ifndef TLV_VALUE_HPP
#define TLV_VALUE_HPP

#include <vector>

namespace TLVComponent
{
    class Value
    {
        public:
            // For use with bad data
            Value()
            {
                _value = std::vector<char>();
            }
            Value(std::vector<char> v) {_value = v;}
            
            bool isValid();
            std::vector<char> getValue() {return _value;}
        private:
            std::vector<char> _value;
    };
}

#endif
