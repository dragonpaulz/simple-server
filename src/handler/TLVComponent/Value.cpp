#include <string>
#include <vector>

#include "Value.hpp"
#include "helper/Byte.hpp"

bool TLVComponent::Value::isValid()
{
    return _value.size() > 1 &&
        TLVhelper::Byte::areHexChar(_value) &&
        _value.size() % 2 == 0;
}

std::string TLVComponent::Value::to_string()
{
    if (!isValid())
    {
        return "";
    }

    // find size of string: _value.size() + 3 new char for every two char - 1 (no space at end)
    // same as: _value.size() + 1.5 * _value.size() - 1
    int newStringSize = _value.size() *2.5 - 1;

    std::vector<char> newString(newStringSize);

    for (uint i = 0; i < _value.size()/2; i++)
    {
        int oldChars = i*2;
        int startIndex = i*5;
        newString[startIndex] = '0';
        newString[startIndex + 1] = 'x';
        newString[startIndex + 2] = _value[oldChars];
        newString[startIndex + 3] = _value[oldChars + 1];
        // do not put ' ' at end of last element
        if (i < (_value.size()/2) - 1) {newString[startIndex + 4] = ' '; }
    }

    std::string s(newString.begin(), newString.end());

    return s;
}
