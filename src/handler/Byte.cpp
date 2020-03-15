#include <string>
#include <iostream>

#include "Byte.hpp"

using byte = handler::Byte;

uint8_t byte::TwoHexToByte(std::string hexStr)
{
    if (hexStr.size() != 2)
    {
        std::cerr << "Unexpected string size. Expecting string of size 2, got "
            << hexStr.size() << ". Returning 0." << std::endl;
        return uint8_t(0);
    }

    if (!isHexChar(hexStr[0]) || !isHexChar(hexStr[1]))
    {
        std::cerr << "Unexpected character. Expecting hexademical characters, received"
            << hexStr << ". Returning 0." << std::endl;
        return uint8_t(0);
    }
    
    return std::stoi(hexStr, nullptr, 16);
}

bool byte::isHexChar(char c)
{
    return (c >= 65 && c <= 70) ||
        (c >= 97 && c <= 102) ||
        (c >= 48 && c <= 57);
}