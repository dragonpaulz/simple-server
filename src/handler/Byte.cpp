#include <string>
#include <iostream>

#include "Byte.hpp"

using byte = handler::Byte;

byte::Byte(bool _value, uint8_t _len)
{
    valid = _value;
    len = _len;
}

byte byte::TwoHexToByte(std::string hexStr)
{
    if (hexStr.size() != 2)
    {
        std::cerr << "Unexpected string size. Expecting string of size 2, got "
            << hexStr.size() << ". Returning 0." << std::endl;
        byte res(false, 0);
        return res;
    }

    if (!isHexChar(hexStr[0]) || !isHexChar(hexStr[1]))
    {
        std::cerr << "Unexpected character. Expecting hexademical characters, received"
            << hexStr << ". Returning 0." << std::endl;
        byte res(false,0);
        return res;
    }
    
    int len = std::stoi(hexStr, nullptr, 16);
    byte res(true, len);

    return res;
}

bool byte::isHexChar(char c)
{
    return (c >= 65 && c <= 70) ||
        (c >= 97 && c <= 102) ||
        (c >= 48 && c <= 57);
}
