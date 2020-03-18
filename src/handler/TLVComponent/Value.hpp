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
                _valid = false;
                _value = std::vector<char>();
            }
            Value(std::vector<char> v) {_value = v;}
            
            bool isValid() {return _valid;}
            std::vector<char> getValue() {return _value;}
        private:
            bool _valid;
            std::vector<char> _value;
    };
}

#endif
